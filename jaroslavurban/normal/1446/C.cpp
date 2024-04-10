#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=40;
int bins[N];
int n;
vector<ll>a;

int dfs(vector<ll>a,ll d){
	vector<ll>ones,zeros;
	for(auto u:a)if(u&(1ll<<d))ones.push_back(u);
	else zeros.push_back(u);
	if(ones.size()<=1&&zeros.size()<=1)return a.size();
	if(ones.size()<=1)return dfs(zeros,d-1)+ones.size();
	if(zeros.size()<=1)return dfs(ones,d-1)+zeros.size();
	return max(1+dfs(ones,d-1),1+dfs(zeros,d-1));
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;a.resize(n);
	for(int i=0;i<n;++i)cin>>a[i];
	cout<<n-dfs(a,40)<<endl;
}