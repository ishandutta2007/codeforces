    #pragma GCC optimize("trapv")
    #include<bits/stdc++.h>
    #define all(x) x.begin(), x.end()
    #define pb push_back
    using namespace std;
    using ll = long long;
    using vi = vector<ll>;
    using pi = pair<ll, ll>;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n, k;
     
    ll ccnt(ll i) {
    	ll l, r, ans = 0;
    	l=i, r=i|1;
    	while(l <= n) {
    		ans += min(n, r)-l+1;
    		l<<=1;
    		r<<=1;
    		r|=1;
    	}
    	return ans;
    }
    int main() {
    	ios::sync_with_stdio(0);
    	cin.tie(0);
    	cin >> n >> k;
    	ll pro = 0;
    	for(ll i = 1ll<<60; i; i>>=1) {
    		if((pro+i)<=n&&ccnt(pro+i)>=k)
    			pro+=i;
    	}
    	cout << pro;
    }