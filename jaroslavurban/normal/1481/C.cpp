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

const int N=100100;
int a[N],b[N],c[N];
vector<int>need[N];
int done[N];
int n,m;

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>m;
		for(int i=0;i<=n;++i)need[i].clear();
		memset(done,-1,sizeof(*done)*(n+1));
		for(int i=0;i<n;++i)cin>>a[i];
		for(int i=0;i<n;++i)cin>>b[i];
		for(int i=0;i<m;++i)cin>>c[i];
		int toremove=0;
		for(int i=0;i<n;++i){
			if(a[i]!=b[i]){
				need[b[i]].push_back(i);
				++toremove;
			}
			done[b[i]]=i;
		}
		int trash=-1;
		bool pos=true;
		vector<int>res(m);
		for(int i=m-1;i>=0;--i){
			if(need[c[i]].size()){
				res[i]=need[c[i]].back();
				trash=need[c[i]].back();
				need[c[i]].pop_back();
				--toremove;
			}
			else if(~trash){
				res[i]=trash;
			}
			else if(~done[c[i]]){
				res[i]=done[c[i]];
				trash=done[c[i]];
			}
			else pos=false;
		}
		if(toremove||!pos)cout<<"NO\n";
		else{
			cout<<"YES\n";
			for(int i=0;i<m;++i)cout<<res[i]+1<<" ";cout<<endl;
		}
	}
}