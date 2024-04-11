#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
typedef pair<int, int> pi;


int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		vector<int> v(n);
		for(auto &i : v) cin >> i;
		set<int> s(v.begin(), v.end());
		if(s.size() > k){
			puts("-1");
			continue;
		}
		vector<int> w;
		for(auto &i : s) w.push_back(i);
		while(w.size() < k) w.push_back(*s.begin());
		printf("%d\n", k * n);
		for(int i=0; i<k*n; i++) printf("%d ", w[i % k]);
		puts("");
	}
}