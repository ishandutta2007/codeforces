#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi mass(500001);
vi where(500001, -1);
int now = 0;

void join(int a, int b, int col, int other) {
	if(mass[a].size() > mass[b].size()) {
		swap(a, b);
	}
	for(const auto& el : mass[a]) {
		mass[b].push_back(el);
	}
	mass[a].clear();
	where[col] = b;
	where[other] = a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int q;
    cin >> q;
    int n = 0;
    for(int i = 0; i < q; i++) {
    	int t;
    	cin >> t;
    	if(t == 1) {
    		int val;
    		cin >> val;
    		if(where[val] == -1) {
    			where[val] = now++;
    		}
    		mass[where[val]].push_back(n);
    		++n;
    	} else {
    		int x, y;
    		cin >> x >> y;
    		if(x == y) continue;
    		if(where[x] == -1) continue;
    		if(where[y] == -1) {
    			where[y] = now++;
    		}
    		join(where[x], where[y], y, x);
    	}
    }
    vi ans(n);
    for(int i = 0; i <= 500000; i++) {
    	if(where[i] == -1) continue;
    	for(const auto& el : mass[where[i]]) {
    		ans[el] = i;
    	}
    }
    for(const auto& el : ans) {
    	cout << el << ' ';
    }
}