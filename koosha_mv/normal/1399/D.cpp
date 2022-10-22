#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
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

int n,c,t,a[N];
string s;

void solve(){
	int ans=0;
	set<int> s0,s1;
	f(i,0,n){
		int c;
		if(s[i]=='0'){
			if(s0.size()){
				c=*s0.begin();
				s0.erase(c);
			}
			else
				ans++,c=ans;
			s1.insert(c);
		}
		else{
			if(s1.size()){
				c=*s1.begin();
				s1.erase(c);
			}
			else
				ans++,c=ans;
			s0.insert(c);
		}
		a[i]=c;
	}
	cout<<ans<<endl;
	print(a,n);
}

int main(){
	cin>>t;
	while(t--){
		cin>>n>>s;
		solve();
	}
}