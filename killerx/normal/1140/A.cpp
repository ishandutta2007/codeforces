#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n;
int a[N];
set<int>st;
vector<int>v[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)v[a[i]].push_back(i);
	int cnt=0;
	for(int i=1;i<=n;++i){
		st.insert(i);
		for(int j=0;j<v[i].size();++j)st.erase(st.find(v[i][j]));
		if(!st.size())++cnt;
	}
	printf("%d\n",cnt);
	return 0;
}