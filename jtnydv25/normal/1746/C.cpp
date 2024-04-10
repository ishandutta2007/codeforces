#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n' // remove in interactive
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		vector<pair<int, int>> diffs;
		int n; cin >> n;
		vector<int> p(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> p[i];
			if(i > 1 && p[i] < p[i - 1]){
				diffs.push_back({p[i - 1] - p[i], i});
			}
		}
		sort(all(diffs), greater<pair<int, int>>());
		vector<int> pos(n + 1, 1);
		int j = 0;
		for(int i = n; i >= 1; i--){
			if(j >= sz(diffs)) continue;
			pos[i] = diffs[j].second;
			j++;
		}
		for(int i = 1; i <= n; i++) cout << pos[i] << " ";
		cout << endl;
	}
}