#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=2e5+99;
ll n,t,a,b;
int main(){
	cin>>t;
	f(q,0,t){
		Get(a,b);
		if(a==b) cout<<0<<endl;
		if(a<b)
			cout<<1+(a%2==b%2)<<endl;
		if(b<a)
			cout<<1+(a%2!=b%2)<<endl;
	}
}