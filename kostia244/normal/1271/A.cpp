    #pragma GCC optimize("trapv")
    #include<bits/stdc++.h>
    #define all(x) x.begin(), x.end()
    #define pb push_back
    using namespace std;
    using ll = long long;
    using vi = vector<ll>;
    using pi = pair<ll, ll>;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
     
    int main() {
    	ios::sync_with_stdio(0);
    	cin.tie(0);
    	ll a, b, c, d, e, f, ans = 0, t;
    	cin >> a >> b >> c >> d >> e >> f;
    	if(e>f) {
    		t = min(a, d);
    		a-=t, d-=t;
    		ans += t*e;
    		t = min({d, b, c});
    		ans += t*f;
    	} else {
    		t = min({d, b, c});
    		ans += t*f;
    		d-=t;
    		t = min(a, d);
    		ans += t*e;
    	}
    	cout << ans << "\n";
    }