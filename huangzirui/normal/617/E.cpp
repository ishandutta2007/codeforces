#include <bits/stdc++.h>
#define int long long
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline int read(){
	char c;int x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
const int maxn=1e5+10;
struct que{
	int l,r,id;
}ask[maxn];
int i,j,k,n,m,N,a[maxn],block[maxn],St[maxn],Sum[maxn],Q[maxn];
ll ans[maxn];
bool cmp(que a,que b){
	return block[a.l]==block[b.l]?a.r<b.r:a.l<b.l;
}
vector<int>V,V2,V3;
int M[2000000],M2[2000000],M3[2000000];
void Mclear(){
	for(int i=0;i<V.size();i++)M[V[i]]=0;
	V.clear();
}
void M2clear(){
	for(int i=0;i<V2.size();i++)M2[V2[i]]=0;
	V2.clear();
}
void M3clear(){
	for(int i=0;i<V3.size();i++)M3[V3[i]]=0;
	V3.clear();
}
signed main() {
	cin>>n>>m>>k;N=sqrt(n);
	for(i=1;i<=n;i++){
		a[i]=read();
		Sum[i]=Sum[i-1]^a[i];
		block[i]=(i-1)/N+1;
		St[block[i]]=St[block[i]]?St[block[i]]:i;
	}
	for(i=1;i<=m;i++)ask[i]={read(),read(),i};
	sort(ask+1,ask+1+m,cmp);
	int l=1,r=0,K=0,last=0;
	for(i=1;i<=m;i++){
		if(block[ask[i].l]==block[ask[i].r]){
			K=0;Mclear();
			for(j=ask[i].l;j<=ask[i].r;j++){
				M[K]++;
				V.push_back(K);
				K^=a[j];
				ans[ask[i].id]+=M[k^K];
			}ask[i].l=0;
			continue;
		}
		int L=block[ask[i].l];
		if(block[ask[i].l]!=block[ask[i-1].l]){
			l=St[L+1];r=l-1;
			K=0;Mclear();
			M2clear();
			last=0;Q[r]=0;
		}
		while(r<ask[i].r){
			r++;
			V.push_back(K);
			M[K]++;
			K^=a[r];
			last+=M[k^K];
			Q[r]=Q[r-1]^a[r];
			V2.push_back(Q[r]);
			M2[Q[r]]++;
		}
		int k2=k;
		M3clear();
		for(j=St[L+1]-1;j>=ask[i].l;j--){
			V3.push_back(k2);
			M3[k2]++;
			k2^=a[j];
			ans[ask[i].id]+=M3[k^k2]+M2[k2];
		}ans[ask[i].id]+=last;
	}
	for(i=1;i<=m;i++)printf("%lld\n",ans[i]);
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}