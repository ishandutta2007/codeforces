#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> g;
vector<int> mt;
vector<char> used;
vector<int> a,b;

bool try_kuhn (int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int main()
{
	int n,m,x,ans=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x;
		a.push_back(x);
	}
	cin >> m;
	for(int i=0; i<m; i++){
		cin >> x;
		b.push_back(x);
	}
	if(n>m){
		swap(n,m);
		swap(a,b);
	}
	for(int i=0; i<n; i++){
		g.push_back(vector<int>());
		for(int j=0;j<m;j++){
			if(a[i]-b[j]<=1 && a[i]-b[j]>=-1){
				g[i].push_back(j);
			}
		}
	}
	mt.assign(m,-1);
	for (int v=0; v<n; ++v) {
		used.assign(n,false);
		if(try_kuhn(v)){
			ans++;
		}
	}
	cout << ans;
	/*for (int i=0; i<m; ++i)
		if (mt[i] != -1)
			printf ("%d %d\n", mt[i]+1, i+1);*/
	return 0;
}