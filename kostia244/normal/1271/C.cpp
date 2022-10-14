    #pragma GCC optimize("trapv")
    #include<bits/stdc++.h>
    #define all(x) x.begin(), x.end()
    #define pb push_back
    using namespace std;
    using ll = long long;
    using vi = vector<ll>;
    using pi = pair<ll, ll>;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n, sx, sy;
    vector<pair<int, int>> a;
    bool in(int l, int r, int x) {
    	if(l>r) swap(l, r);
    	return l <= x && x <= r;
    }
    int check(int x, int y) {
    	int t = 0;
    	for(auto i : a) {
    		t += in(sx, i.first, x)&&in(sy, i.second, y);
    	}
    	return t;
    }
    int main() {
    	ios::sync_with_stdio(0);
    	cin.tie(0);
    	cin >> n >> sx >> sy;
    	a.resize(n);
    	for(auto &i : a) cin >> i.first >> i.second;
    	int px = sx, py = sy, ans = -100;
    	for(int u = -1; u < 2; u++)
    		for(int v = -1; v < 2; v++) {
    			if(u==0&&v==0) continue;
    			if(int t = check(sx+u, sy+v); t > ans) {
    				px = sx+u, py = sy+v, ans = t;
    			}
    		}
    	cout << ans << "\n" << px << " " << py;
    }