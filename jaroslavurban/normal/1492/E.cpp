#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// bool xd=any_of(a.begin(),a.end(),[&](int x){return x==9;});
// all_of, none_of
// int cnt=count(a.begin(),a.end(),x);
// bool found=binary_search(a.begin(),a.end(),x); true if x in sorted array
// int xd=*max_element(a.begin(),a.end());
// min_element

typedef long long ll;
typedef long double ld;

const int N=250100;
vector<int>g[N];
int n,m;

vector<int>diffs(vector<int>&a,vector<int>&b){
	vector<int>res;
	for(int i=0;i<m;++i)if(a[i]!=b[i])res.push_back(i);
	return res;
}

int tr(vector<int>&a){
	for(int i=0;i<n;++i){
		if(diffs(a,g[i]).size()<3)continue;
		if(diffs(a,g[i]).size()==3&&count(a.begin(),a.end(),0)){
			for(int j=0;j<m;++j)if(!a[j]){a[j]=g[i][j];break;}
			continue;
		}
		return 0;
	}
	if(count(a.begin(),a.end(),0))
		for(int j=0;j<m;++j)if(!a[j])a[j]=g[0][j];
	return 1;
}


main(){
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;++i)g[i].resize(m);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin>>g[i][j];
	for(int i=1;i<n;++i){
		vector<int>dfs=diffs(g[i],g[0]);
		if(dfs.size()<3)continue;
		vector<int>cur=g[0];
		if(dfs.size()==3){
			do{
				cur[dfs[0]]=g[0][dfs[0]];
				cur[dfs[1]]=g[i][dfs[1]];
				cur[dfs[2]]=0;
				if(tr(cur)){
					cout<<"Yes\n";
					for(auto r:cur)cout<<r<<" ";cout<<endl;
					return 0;
				}
			}while(next_permutation(dfs.begin(),dfs.end()));
		}
		if(dfs.size()==4){
			do{
				cur[dfs[0]]=g[0][dfs[0]];
				cur[dfs[1]]=g[0][dfs[1]];
				cur[dfs[2]]=g[i][dfs[2]];
				cur[dfs[3]]=g[i][dfs[3]];
				if(tr(cur)){
					cout<<"Yes\n";
					for(auto r:cur)cout<<r<<" ";cout<<endl;
					return 0;
				}
			}while(next_permutation(dfs.begin(),dfs.end()));
		}
		cout<<"No\n";return 0;
	}
	cout<<"Yes\n";
	for(auto r:g[0])cout<<r<<" ";cout<<endl;
}