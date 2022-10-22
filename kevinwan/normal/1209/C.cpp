#include<bits/stdc++.h>
#ifdef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=2e5+10;
int ans[mn];
bool u[mn];
bool check(string&v,int d){
	memset(u,0,sizeof(u));
	vector<int>s;
	for(int i=0;i<v.size();i++)if(v[i]<=d){
		while(s.size()&&v[s.back()]>v[i])s.pop_back();
		s.push_back(i);
	}
	for(int x:s)u[x]=1,ans[x]=1;
	for(int i=0;i<v.size();i++)if(!u[i])s.push_back(i),ans[i]=2;
	for(int i=0;i+1<s.size();i++)if(v[s[i]]>v[s[i+1]])return 0;
	return 1;
}
int main(){
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	#else
		cin.tie(0);
		cin.sync_with_stdio(0);
	#endif
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		for(char&c:s)c-='0';
		bool done=0;
		for(int i=0;i<=9;i++)if(check(s,i)){
			done=1;
			for(int i=0;i<n;i++)printf("%d",ans[i]);
				break;
		}
		if(!done)printf("-\n");
		else printf("\n");
	}
}