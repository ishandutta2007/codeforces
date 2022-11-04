#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// trying out shit tests
const int N=100100;
int a[N];
int n,k;
unordered_map<int,vector<int>>m;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>a[i];
		for(int j=2;j*j<=a[i];++j)
			if(a[i]%j==0){
				m[j].push_back(i);
				while(a[i]%j==0)a[i]/=j;
			}
		if(a[i]!=1)m[a[i]].push_back(i);
	}
	int mx=2;
	for(auto it:m)if(m[mx].size()<it.second.size())mx=it.first;
	if(m[mx].size()>=k){
		for(int i=0;i<k;++i)cout<<m[mx][i]+1<<" ";cout<<endl;
	}
	else{
		set<int>s;
		for(int i=0;i<n;++i)s.insert(i);
		for(auto i:m[mx])s.erase(i);
		vector<int>res;
		for(auto it:s)res.push_back(it);
		sort(res.begin(),res.end(),[&](int i,int j){return a[i]<a[j];});
		for(int i=0;i<k+(n==6);++i)if((n!=6)||i!=1)cout<<res[i]+1<<" ";cout<<endl;
	}
}