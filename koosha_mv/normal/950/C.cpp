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
const int N=3e5+9;
int n,t0,t1,c,mn,mx,t;
string s;
set<int> s0,s1;
vector<int> ans[N];
int main(){
	cin>>s;
	n=s.size();
	f(i,0,n){
		t0+=(s[i]=='0');
		t1+=(s[i]=='1');
		if(t0<t1) return cout<<-1,0;
	}
	t=t0-t1;
	if(t0<=t1) return cout<<-1,0;
	t0=0,t1=0;
	f(i,0,n){
		t0+=(s[i]=='0');
		t1+=(s[i]=='1');
		maxm(mx,t0-t1);
	}
	if(mx>t) return cout<<-1,0;
	f(i,0,n){
		if(s[i]=='1'){
			mn=*s0.begin();
			s0.erase(mn);
			ans[mn].pb(i+1);
			s1.insert(mn);
		}
		else{
			if(s1.size()){
				mn=*s1.begin();
				s1.erase(mn);
				ans[mn].pb(i+1);
				s0.insert(mn);
			}
			else{
				ans[c].pb(i+1);
				s0.insert(c++);
			}
		}
	}
	cout<<c<<endl;
	f(i,0,c){
		cout<<ans[i].size()<<" ";
		f(j,0,ans[i].size()) cout<<ans[i][j]<<" ";
		cout<<endl;
	}
}