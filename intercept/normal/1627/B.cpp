#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
void work(){
	int n,m;
	cin>>n>>m;
	vector<int>p;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			p.eb(max(i-1,n-i)+max(j-1,m-j));
		}
	}
	sort(p.begin(),p.end());
	for(auto o:p)cout<<o<<" ";
	puts("");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
3 5
-2 -7 -1
*/