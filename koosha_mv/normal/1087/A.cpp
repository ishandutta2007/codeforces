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
const int N=501;
int n,t,a[N],x;
string s,ans;
int main(){
	cin>>s;
	n=s.size();
	if(s.size()%2){
		t=1;
		x=n/2;
		f(i,0,s.size()){
			cout<<s[x];
			if(i%2)x-=t++;
			else x+=t++;
		}
	}
	else{
		x=n/2-1;
		t=1;
		f(i,0,s.size()){
			cout<<s[x];
			if(i%2)x-=t++;
			else x+=t++;
		}
	}
}