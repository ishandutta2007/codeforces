#include <bits/stdc++.h>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+99,lg=30;

int n,a[N],OR[N][lg];
map<int,int> mark;
ll ans;

int Or(int l,int r){
	int res=0;
	l--;
	f(i,0,lg)
		res+=(1<<i)*(OR[l][i]<OR[r][i]);
	return res;
}
int solve(int x){
	int l=mark[a[x]],r=x,mid,res;
	while(l+1<r){
		mid=(l+r)/2;
		if(Or(mid,x)<=a[x]) r=mid;
		else l=mid;
	}
	res=x-l;
	l=x,r=n+1;
	while(l+1<r){
		mid=(l+r)/2;
		if(Or(x,mid)<=a[x]) l=mid;
		else r=mid;
	}
	ans+=1ll*res*(r-x);
	mark[a[x]]=x;
}

int main(){
	cin>>n;
	f(i,1,n+1){ 
		gett(a[i]);
		f(j,0,lg)
			OR[i][j]=OR[i-1][j]+is_bit(a[i],j);
	}
	f(i,1,n+1)
		solve(i);
	cout<<1ll*n*(n+1)/2-ans;
}