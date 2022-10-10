#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt --){
		int n, m;
		cin >> n >> m;
		vector<bool> av(3 * n, true);
		vi matching;
		for(int i = 1; i <= m; i ++){
			int u, v;
			cin >> u >> v, u --, v --;
			if(av[u] && av[v]){
				matching.push_back(i);
				av[u] = av[v] = false;
			}
		}
		if(matching.size() >= n){
			cout << "Matching\n";
			for(int i = 0; i < n; i ++){
				cout << matching[i] << " ";
			}
			cout << "\n";
		}
		else{
			cout << "IndSet\n";
			for(int i = 0, j = 0; i < n; j ++){
				if(av[j]){
					cout << j + 1 << " ";
					i ++;
				}
			}
			cout << "\n";
		}
	}
	return 0;
}