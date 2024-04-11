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
const int N=2e5+9;
ll n,t,a,b,c,mx;
int main(){
	cin>>t;
	f(q,0,t){
		mx=0;
		cin>>a>>b>>c>>n;
		mx=max(a,max(b,c));
		n-=(mx-a)+(mx-c)+(mx-b);
		if(n%3==0 && n>=0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}