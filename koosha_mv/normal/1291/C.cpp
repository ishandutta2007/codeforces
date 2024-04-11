#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=3600;
ll n,t,m,k,a[N],e=1e10,ans[N],po,sfr;
int main(){
	cin>>t;
	f(q,0,t){
		set <ll> s;
		cin>>n>>m>>k;
		k=min(k,m-1);
		f(i,0,n+1) ans[i]=1e9;
		f(i,0,n)	get(a[i]);
		ll fa=n-m;
		f(i,0,n-fa){
			//cout<<i<<" : "<<max(k-(n-(i+fa)),sfr)<<" & "<<i+1<<endl;
			f(j,max(k-(n-(i+fa)-1),(ll)0),i+1){
				minm(ans[j],max(a[i],a[i+fa]))
			}
		}
		po=0;
		f(i,0,k+1)
			maxm(po,ans[i]);
		cout<<po<<endl;
	}
}