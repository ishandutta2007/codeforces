#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,m,q,x;
string s1[22],s2[22];
int main(){
	cin>>n>>m;
	f(i,0,n) cin>>s1[i];
	f(i,0,m) cin>>s2[i];
	cin>>q;
	f(i,0,q){
		cin>>x;x--;
		cout<<s1[(x%n)]+s2[x%m]<<endl;
	}
}