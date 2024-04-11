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
string a,b;
vector<int> ans;

char p(char x){
	if(x=='1') return '0';
	return '1';
}
int main(){
	cin>>t;
	while(t--){
		ans.clear();
		cin>>n;
		cin>>a>>b;
		char last=a[0];
		f(i,0,n){
			if(a[i]!=last)
				ans.pb(i),last=p(last);
		}
		f_(i,n-1,0)
			if(last!=b[i])
				ans.pb(i+1),last=p(last);
		cout<<ans.size()<<endl;
		f(i,0,ans.size()) cout<<ans[i]<<" "; cout<<endl;
	}
}