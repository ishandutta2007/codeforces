#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=3e5+9;
ll n,t,k,tdd,mark[27],e=1e4,s1,s2;
string s,ans;
vector<int> g[27];
map<ll,ll> m;
void dfs(int x){
	ans+=char(x+'a');
	mark[x]=1;
	if(g[x].size()>=3) {
		k=1;
	}
	f(i,0,g[x].size()){
		if(mark[g[x][i]]==0)
			dfs(g[x][i]);
	}
}
int main(){
	cin>>t;
	f(q,0,t){
		cin>>s;
		
		f(i,0,27) mark[i]=0,g[i].clear();
		k=0;
		ans="";
		f(i,0,s.size()-1){
			s1=s[i]*e+s[i+1];
			s2=s[i+1]*e+s[i];
			if(m[s1]==0){
				m[s1]=1,m[s2]=1;
				g[s[i]-'a'].pb(s[i+1]-'a');
				g[s[i+1]-'a'].pb(s[i]-'a');
			}
		}
		f(i,0,s.size()-1){
			s1=s[i]*e+s[i+1];
			s2=s[i+1]*e+s[i];
			m[s1]=0,m[s2]=0;
		}
		f(i,0,26){
			if(mark[i]==0 && g[i].size()<=1){
				dfs(i);
			}
		}

		if(k==1 || ans.size()<26) cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			cout<<ans<<endl;
		}
	}	
}