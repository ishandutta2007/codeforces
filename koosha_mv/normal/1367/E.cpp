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
#define Add(x,y) x=(x+y)%mod;
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,t,k,g,sz,c[60];
string s;

bool check(int x){
	g=__gcd(x,k),sz=x/g;
	int ans=0;
	f(i,0,40)
		ans+=c[i]/sz;
	return (ans>=g);
}
void solve(){
	f(i,0,50) c[i]=0;
	cin>>n>>k>>s;
	f(i,0,n) c[s[i]-'a']++;
	f_(i,n,1)
		if(check(i)){
			cout<<i<<endl;
			return ;
		}
}

int main(){
	cin>>t;
	f(q,0,t)
		solve();
}