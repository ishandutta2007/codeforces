#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// bool xd=any_of(a.begin(),a.end(),[&](int x){return x==9;});
// all_of, none_of
// int cnt=count(a.begin(),a.end(),x);
// bool found=binary_search(a.begin(),a.end(),x); true if x in sorted array
// int xd=*max_element(a.begin(),a.end());
// min_element

typedef long long ll;
typedef long double ld;

const int N=100100,A=27,M=A*A*A*A+10,K=4;
int n,m,k;
string pat[N],str[N];
int want[N];
int id[M],par[M];
vector<int>g[M];

int gid(char c){
	return c=='_'?26:c-'a';
}

int getid(string &s){
	return gid(s[0])+A*gid(s[1])+A*A*gid(s[2])+A*A*A*gid(s[3]);
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=0;i<n;++i)cin>>pat[i];
	for(int i=0;i<m;++i)cin>>str[i]>>want[i];
	for(int i=0;i<m;++i)str[i]+=string(K-k,'a');
	for(int i=0;i<n;++i)pat[i]+=string(K-k,'a');
	memset(id,-1,sizeof(id));
	for(int i=0;i<n;++i)id[getid(pat[i])]=i;
	unordered_set<int>sources;
	for(int i=0;i<n;++i)sources.insert(getid(pat[i]));
	for(int i=0;i<m;++i){
		bool ok=false;
		for(int j=0;j<(1<<K);++j){
			string p=str[i];
			for(int kk=0;kk<K;++kk)if(j&(1<<kk))p[kk]='_';
			if(p!=pat[want[i]-1]&&~id[getid(p)]){
				g[getid(pat[want[i]-1])].push_back(getid(p));
				sources.erase(getid(p));
				++par[getid(p)];
			}else if(p==pat[want[i]-1])ok=true;
		}
		if(!ok){cout<<"NO\n";return 0;}
	}
	vector<int>res;
	while(sources.size()){
		int u=*sources.begin();
		sources.erase(u);
		res.push_back(id[u]);
		for(auto v:g[u])if(!--par[v])sources.insert(v);
	}
	if(res.size()!=n)cout<<"NO\n";
	else{
		cout<<"YES\n";
		for(int i=0;i<n;++i)cout<<1+res[i]<<" ";cout<<endl;
	}
}