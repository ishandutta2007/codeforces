#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=3e5+99;
int n,m,k;
int main(){
	cin>>n>>m>>k;
	cout<<n+m+(n*m)-1<<endl;
	f(i,0,n) cout<<'U';
	f(i,0,m) cout<<'L';
	f(i,0,n){
		if(i%2==0){
			f(j,0,m-1) cout<<'R';
		}
		else{
			f(j,0,m-1) cout<<'L';
		}
		if(i!=n-1)
			cout<<'D';
	}
}