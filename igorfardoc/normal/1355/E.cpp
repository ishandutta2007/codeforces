#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, a, r, m;
vi b;

ll check(int h) {
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		sum += b[i];
	}
	bool needm = m < r + a;
	ll res = 0;
	ll delta = abs(sum - (ll)h * n);
	bool needadd = sum < (ll)h * n;
	if(needadd) {
		res += (ll)a * delta;
	} else {
		res += (ll)r * delta;
	}
	for(int i = 0; i < n; i++) {
		if(b[i] <= h) {
			continue;
		}
		int here = b[i];
		if(!needadd) {
			int can = min((ll)here - h, delta);
			delta -= can;
			here -= can;
		}
		if(needm) {
			res += (ll)(here - h) * m;
		} else {
			res += (ll)(here - h) * (a + r);
		}
	}
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
    cin >> n >> a >> r >> m;
   	b.resize(n);
    for(int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    int l = 0;
    int r = 1000000000;
    ll ans = 1000000000000000000ll;
    while(r - l > 2) {
    	int mid1 = l + (r - l) / 3;
    	int mid2 = r - (r - l) / 3;
    	ll res1 = check(mid1);
    	ll res2 = check(mid2);
    	if(res1 > res2) {
    		l = mid1;
    	} else {
    		r = mid2;
    	}
    }
    for(int i = l; i <= r; i++) {
    	ans = min(ans, check(i));
    }
    cout << ans;
}