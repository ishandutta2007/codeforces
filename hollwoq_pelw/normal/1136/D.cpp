#include <bits/stdc++.h>
using namespace std;

int n,m,i,j,x,y,p[300005],f[300005],ans;
set<int> s[300005];
vector<int> all;
int main(){
	cin>>n>>m;
	for (int i = 1; i <= n; i++){
	    cin>>x;
		p[x]=i;
	}
	for (int i = 1; i <= m; i++){
		cin>>x>>y;
		x=p[x];y=p[y];
		s[x].insert(y);
	}
	all.push_back(n);
	for(int i = n - 1; i >= 1; i--){
		for (j = 0; j < all.size(); j++) if (!s[i].count(all[j])) break;
		if (j==all.size()) ans++; 
		else all.push_back(i);
	}
	cout<<ans<<endl; 
	return 0;
}