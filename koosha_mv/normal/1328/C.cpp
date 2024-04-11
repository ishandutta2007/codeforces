#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops cout<<"!"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=2e5+99;
int t,n;
string s;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>s;
		int p=0;
		while(p<n && s[p]!='1')
			p++;
		f(i,0,n){
			if(i<p){
				if(s[i]=='2') cout<<1;
				else cout<<0;
			}
			else{
				if(i==p) cout<<1;
				else cout<<0;
			}
		}
		cout<<endl;
		f(i,0,n){
			if(i<p){
				if(s[i]=='2') cout<<1;
				else cout<<0;
			}
			else{
				if(i==p) cout<<0;
				else cout<<s[i];
			}
		}
		cout<<endl;
	}
}