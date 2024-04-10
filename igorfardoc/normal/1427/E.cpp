#include<bits/stdc++.h>
#define INF 500000000000000000ll
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

bool solve(vector<ll> ch, vi& ans) {
	vvi a(61, vi(ch.size() + 1, 0));
	for(int i = 0; i < ch.size(); i++) {
		for(int j = 0; j < 61; j++) {
			if((ch[i] >> j) & 1) {
				a[j][i] = 1;
			}
		}
	}
	a[0][ch.size()] = 1;
	int n = a.size();
	int m = a[0].size() - 1;
	vi where(m, -1);
	for(int col = 0, row = 0; col < m && row < n; ++col) {
		int sel = row;
		for(int i = row; i < n; i++) {
			if(a[i][col] == 1) {
				sel = i;
				break;
			}
		}
		if(a[sel][col] == 0) {
			continue;
		}
		for(int i = col; i <= m; i++) {
			swap(a[row][i], a[sel][i]);
		}
		where[col] = row;
		for(int i = 0; i < n; i++) {
			if(i == row || a[i][col] == 0) continue;
			for(int j = col; j <= m; j++) {
				a[i][j] = a[i][j] ^ a[row][j];
			}
		}
		++row;
	}
	ans.assign(m, 0);
	for(int i = 0; i < m; i++) {
		if(where[i] == -1) continue;
		ans[i] = a[where[i]][m];
	}
	for(int i = 0; i < n; i++) {
		int sum = 0;
		for(int j = 0; j < m; j++) {
			sum += ans[j] * a[i][j];
		}
		if(sum % 2 != a[i][m]) {
			return false;
		}
	}
	return true;
}
mt19937 rnd;


int get_random(int l, int r) {
	uniform_int_distribution<int> rng(l, r);
	return rng(rnd);
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
    int x;
    cin >> x;
    vector<ll> here;
    here.push_back(x);
    vector<pair<pair<ll, ll>, char>> res;
    while(true) {
    	bool ok = false;
    	ll now = here[here.size() - 1];
    	for(int i = here.size() - 1; i >= 0; i--) {
    		if(now + here[i] <= INF) {
    			ok = true;
    			res.push_back({{now, here[i]}, '+'});
    			here.push_back(now + here[i]);
    			break;
    		}
    	}
    	if(!ok) {
    		break;
    	}
    }
    
    while(here.size() < 400) {
    	ll fir = here[get_random(0, here.size() - 1)];
    	ll sec = here[get_random(0, here.size() - 1)];
    	char sign = '+';
    	ll res1 = fir + sec;
    	if(get_random(0, 1) == 0) {
    		sign = '^';
    		res1 = fir ^ sec;
    	}
    	if(res1 > INF) {
    		continue;
    	}
    	res.push_back({{fir, sec}, sign});
    	here.push_back(res1);
    }
    vi ans;
    if(!solve(here, ans)) {
    	cout << '+' << '\n';
    	return 0;
    }
    ll last = -1;
    for(int i = 0; i < ans.size(); i++) {
    	if(ans[i]) { 
    		if(last == -1) {
    			last = here[i];
    		} else {
    			res.push_back({{last, here[i]}, '^'});
    			last = last ^ here[i];
    		}
    	}
    }
    cout << res.size() << '\n';
    for(const auto& el : res) {
    	cout << el.first.first << ' ' << el.second << ' ' << el.first.second << '\n';
    }
}