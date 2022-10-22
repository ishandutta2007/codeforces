#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N=4100,Q=7e4,B=256,CB=N/B+1;
int n,q,a[N],cB,l,r,ans[Q],bf[B+3][B+3],ok[B+3];
vector<pair<int,int>>opt;
int mg(int x,int y){
	if(!x||!y)return x|y;
	opt.emplace_back(x,y);
	return opt.size()+n;
}
struct node{
	int p[B+3],s[B+3],rs[B+3][B+3],C,P[N],S[N];
	void ins(int x){p[++C]=x,s[C]=C;}
	int solve(int l,int r){
		if(l==r)return a[p[s[l]]];
		int mid=(l+r)/2,sl=0,sr=0,ml=solve(l,mid),mr=solve(mid+1,r);
		inplace_merge(s+l,s+mid+1,s+r+1);
		FOR(i,l,r)ok[i]=a[p[s[i]]]<=ml;
		ROF(i,r,l){
			ok[i]?sl=s[i]:sr=s[i];
			int pl=0,pr=0;
			FOR(j,i,r){
				ok[j]?pl=s[j]:pr=s[j];
				bf[s[i]][s[j]]=mg(rs[sl][pl],rs[sr][pr]);
			}
		}
		FOR(i,l,r)FOR(j,i,r)rs[s[i]][s[j]]=bf[s[i]][s[j]];
		return max(ml,mr);
	}
	void work(){
		sort(s+1,s+C+1,[&](int x,int y){return a[p[x]]<a[p[y]];});
		FOR(i,1,C)rs[i][i]=p[i],P[p[i]]=S[p[i]]=i;
		FOR(i,1,n)if(!P[i])P[i]=P[i-1];
		ROF(i,n,1)if(!S[i])S[i]=S[i+1];
		solve(1,C);
	}
	void F(int i){ans[i]=mg(ans[i],rs[S[l]][P[r]]);}
}b[CB];
int get(int x){return (x-1)/B+1;}
int main(){
	scanf("%d%d",&n,&q),cB=get(n);
	FOR(i,1,n)scanf("%d",a+i),b[get(a[i])].ins(i);
	FOR(i,1,cB)b[i].work();
	FOR(i,1,q){
		scanf("%d%d",&l,&r);
		FOR(j,1,cB)b[j].F(i);
	}
	printf("%d\n",opt.size()+n);
	for(auto k:opt)printf("%d %d\n",k.first,k.second);
	FOR(i,1,q)printf("%d ",ans[i]);
	return 0;
}