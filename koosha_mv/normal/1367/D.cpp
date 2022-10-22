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
#define Add(x,y) x=(x+y)%mod;
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=200;

int n,t,p,a[N],c[N];
string s,ans;

int calc(int x){
	int res=0;
	f(i,0,n)
		if(ans[i]!=' ')
			res+=abs(x-i);
	return res;
}
void solve(){
	int m=0;
	vector<int> v;
	f(i,0,n)
		if(ans[i]==' ' && calc(i)==a[i]){
			v.pb(i);
			m++;
		}
	while(c[p]<m)
		p--;
	f(i,0,v.size())
		ans[v[i]]=char(p);
	p--;
}

int main(){
	cin>>t;
	f(q,0,t){
		f(i,0,N) c[i]=0;
		p=int('z');
		ans="";
		cin>>s>>n;
		f(i,0,s.size()) c[s[i]]++;
		f(i,0,n){ cin>>a[i];}
		f(i,0,n) ans+=' ';
		f(i,0,n)
			solve();
		cout<<ans<<endl;
	}
}