#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,x,y,e=1e15,p,mx=-1;
int main(){
	cin>>x>>y>>n;
	f(i,1,1e6){
		x*=10;
		if(x/y==n){
			cout<<i;return 0;
		}
		x%=y;
	}
	cout<<-1;
}