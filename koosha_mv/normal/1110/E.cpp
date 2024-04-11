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
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=1e5+9;

int n,a[N],t[N];
map<int,int> mp1,mp2;

int main(){
	cin>>n;
	f(i,0,n) gett(a[i]);
	f(i,0,n) gett(t[i]);
	if(a[0]!=t[0]) return cout<<"NO",0;
	f(i,1,n)
		mp1[a[i]-a[i-1]]++;
	f(i,1,n){
		mp2[t[i]-t[i-1]]++;
		if(mp2[t[i]-t[i-1]]>mp1[t[i]-t[i-1]]) return cout<<"NO",0;
	}
	cout<<"YES";
}