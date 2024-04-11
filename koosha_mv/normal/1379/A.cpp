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
#define ops(x) cout<<x<<" !"<<endl
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,t;
string s,a="abacaba",b;

int check(string g,int x){
	int p1=0;
	f(i,0,a.size()){
		if(g[i+x]=='?') p1=1;
		else
			if(g[i+x]!=a[i]) return 0;
	}
	if(p1) return 2;
	return 1;
}
void make_b(int x){
	b="";
	f(i,0,n){
		if(i>=x && i-x<a.size())
			b+=a[i-x];
		else
			b+=(s[i]=='?' ? 'z':s[i]);
	}
}
bool is_b_c(){
	int res=0;
	f(i,0,n-a.size()+1)
		res+=(check(b,i)==1);
	if(res>1) return 0;
	return 1;
}

int main(){
	cin>>t;
	f(q,0,t){
		cin>>n>>s;
		string ans="";
		f(i,0,n-a.size()+1)
			if(check(s,i)){
				make_b(i);
				if(is_b_c()){
					ans=b;
				}
			}
		if(ans.size()){
			cout<<"YES"<<endl;
			cout<<ans<<endl;
		}
		else cout<<"NO"<<endl;
	}
}