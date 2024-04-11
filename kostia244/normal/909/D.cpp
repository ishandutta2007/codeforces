#include<bits/extc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 1<<20, mod = 1e9 + 7;
string s;
int n;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> s;
	s += "F";
	vector<pair<char, int>> cur;
	char lst = '0';
	int c = 0;
	for(auto i : s) {
		if(i != lst) {
			if(c) cur.push_back({lst, c});
			c = 0;
		}
		c++, lst = i;
	}
	int iter = 0;
	while(cur.size() > 1) {
		vector<pair<char, int>> nxt;
		for(int i = 0; i < cur.size(); i++) {
			cur[i].second -= 1 + (i+1!=cur.size()&&i);
			if(cur[i].second > 0) {
				if(nxt.size() && nxt.back().first == cur[i].first) nxt.back().second += cur[i].second;
				else nxt.push_back(cur[i]);
			}
		}
		cur = nxt;
		iter++;
	}
	cout << iter << endl;
}