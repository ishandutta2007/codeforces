#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> deg(n);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		deg[u - 1] ++, deg[v - 1] ++;
	}
	cout << (all_of(deg.begin(), deg.end(), [](int d){return d != 2;}) ? "YES" : "NO") << "\n";
	return 0;
}