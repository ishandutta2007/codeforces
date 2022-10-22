#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=40;
ll n,t,k,a[N],b[N],mark[N*2],ans;
void solve(ll x){
	f(i,0,N*2){
		if(x%k>1) ans=0;
		if(x%k==1) mark[i]++;
		if(mark[i]>1) ans=0;
		x/=k;
	}
}
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n>>k;
		ans=1;
		fill(mark,mark+N*2,0);
		f(i,0,n){
			cin>>a[i];
			solve(a[i]);
		}
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}