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

const int N=3e5+9;
ll n,t,ans;
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n;
		ans=0;
		while(n>=10){
			ans+=n/10*10;
			n=n-((n/10)*9);
		}
		ans+=n;
		cout<<ans<<endl;
	}
}