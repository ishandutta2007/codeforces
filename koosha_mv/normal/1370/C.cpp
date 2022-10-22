#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
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

int n,t,ans;

string s1="Ashishgup",s2="FastestFinger";

string solve(){
	for(int i=2;i<32;i++)
		if(n==(1<<i))
			return s2;
	if(n==1) return s2;
	if(n%2==1 || n==2) return s1;
	if(n%4==0) return s1;
	ans=0;
	n/=2;
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return s1;
	return s2;
}

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		cout<<solve()<<endl;
	}
}