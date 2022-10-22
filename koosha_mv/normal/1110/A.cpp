#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
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
const int N=3e5+99;
int n,t,a[N],b,k;
ll sum;
int main(){
	cin>>b>>k;
	f(i,0,k){gett(a[i]);sum+=a[i];}
	if(b%2==0){
		if(a[k-1]%2==0) cout<<"even";
		else cout<<"odd";
	}
	else{
		if(sum%2) cout<<"odd";
		else cout<<"even";
	}
}