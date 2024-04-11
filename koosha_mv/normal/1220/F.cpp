#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+9,inf=1e9;

int n,l,r,p1,an,mid,ans,A[N],a[N];
pair<int,int> p,tree[N*2];

int query(int l, int r) {
	pair<int,int> res;r++;
	res.F=inf;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
   	if(l&1){
			if(tree[l]<res)
				res=tree[l];
			l++;
		}
   	if(r&1)
   		if(tree[--r]<res)
   			res=tree[r];
	}
  	return res.S;
}
void make(){
	f(i,n,2*n)
		tree[i]=mp(a[i-n],i-n);
	f_(i,n-1,1){
		if(tree[i*2]<tree[i*2+1]) tree[i]=tree[i*2];
		else tree[i]=tree[i*2+1];
	}
}
int calc(int l,int r){
	int res;
	if(r<l) return 0;
	int u=query(l,r);
	res=max(calc(l,u-1),calc(u+1,r))+1;
	return res;
}
int check(int x){
	p.F=calc(1,x);
	p.S=calc(x+1,n-1);
	return max(p.F,p.S)+1;
}
void solve(){
	l=0,r=n-1;
	while(l+1<r){
		mid=(l+r)/2;
		check(mid);
		if(p.F<=p.S) l=mid;
		else r=mid; 
	}
}
int main(){
	cin>>n;
	f(i,0,n){
		cin>>A[i];
		if(A[i]==1)
			p1=i;
	}
	for(int i=p1;an<n;i=(i+1)%n)
		a[an++]=A[i];
	make();
	solve();
	cout<<check(l)<<" "<<(p1-(n-l-1)+n)%n<<endl;
}