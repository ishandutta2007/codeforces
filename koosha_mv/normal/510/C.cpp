#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=200;
int n,deg[N];
vector<int> g[N],sefra;
string s[N];
vector<char> ans;
bool check_pr(string s1,string s2){
	if(s2.size()<s1.size()) return 0;
	f(i,0,s1.size()){
		if(s1[i]!=s2[i]) return 0;
	}
	return 1;
}
void add_edge(string s1,string s2){
	if(check_pr(s2,s1)){
		cout<<"Impossible";
		exit(0);
	}
	f(i,0,s1.size()){
		if(s1[i]!=s2[i]){
			g[s1[i]-'a'].pb(s2[i]-'a');
			deg[s2[i]-'a']++;
			return ;
		}
	}
}
int main(){
	cin>>n;
	f(i,0,n)
		cin>>s[i];
	f(i,1,n){
		add_edge(s[i-1],s[i]);
	}
	f(i,0,26)
		if(deg[i]==0)
			sefra.pb(i);
	while(sefra.size()){
		int u=sefra[sefra.size()-1];
		ans.pb(char('a'+u));
		sefra.pop_back();
		f(i,0,g[u].size()){
			if(--deg[g[u][i]]==0)
				sefra.pb(g[u][i]);
		}
	}
	if(ans.size()==26){
		f(i,0,ans.size())	cout<<ans[i];
	}
	else
		cout<<"Impossible";
}