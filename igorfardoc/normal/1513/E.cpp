#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;
int fact[300000], rfact[300000];
int bin_pow(int a, int b) {
	if(b == 0) return 1;
	int res = bin_pow(a, b >> 1);
	res = ((ll)res * res) % mod;
	if(b & 1) {
		res = ((ll)res * a) % mod;
	}
	return res;
}
int obr(int a) {
	return bin_pow(a, mod - 2);
}

int c(int n, int k) {
	if(n < 0 || k < 0 || k > n) {
		return 0;
	}
	int res = ((ll)fact[n] * rfact[k]) % mod;
	res = ((ll)res * rfact[n - k]) % mod;
	return res;
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
    fact[0] = 1;
    for(int i = 1; i < 300000; i++) {
    	fact[i] = ((ll)fact[i - 1] * i) % mod;
    	rfact[i] = obr(fact[i]);
    }
    rfact[0] = rfact[1];
    int n;
    cin >> n;
    vi a(n);
    ll sum = 0;
    map<int, int> am;
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    	sum += a[i];
    	++am[a[i]];
    }
    if(sum % n != 0) {
    	cout << 0;
    	return 0;
    }
    int mid = sum / n;
    int ambig = 0;
    int amsmall = 0;
    int ameq = 0;
    for(int i = 0; i < n; i++) {
    	if(a[i] > mid) {
    		++ambig;
    	} else if(a[i] < mid) {
    		++amsmall;
    	} else {
    		++ameq;
    	}
    }
    int ans = 0;
    if(amsmall == 0 || ambig == 0) {
    	cout << 1;
    	return 0;
    }
    int div = 1;
    for(const auto& el : am) {
    	div = ((ll)div * fact[el.second]) % mod;
    }
    if(amsmall == 1 || ambig == 1) {
    	cout << (ll)fact[n] * obr(div) % mod;
    	return 0;
    }
    ans = (ll)fact[amsmall] * fact[ambig] % mod;
    ans = (ll)c(n, ameq) * ans % mod * fact[ameq] % mod;
    ans = (ll)ans * obr(div) * 2 % mod;
    cout << ans;
}