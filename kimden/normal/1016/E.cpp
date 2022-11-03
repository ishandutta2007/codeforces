#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);

    ll sy, a, b;
    cin >> sy >> a >> b;
    sy = -sy;
    int n;
    cin >> n;
    vector<ll> v(2 * n);
    vector<ll> preflen(n + 1);
    preflen[0] = 0;
    for(int i = 0; i < n; ++i){
    	cin >> v[2 * i] >> v[2 * i + 1];
    	preflen[i + 1] = preflen[i] + v[2 * i + 1] - v[2 * i];
    }
    int q;
    cin >> q;
    ll x, y;
    for(int i = 0; i < q; ++i){
    	cin >> x >> y;
    	ld aa = (x * sy + a * y) / ld(y + sy);
    	ld bb = (x * sy + b * y) / ld(y + sy);
    	int first, second;
    	if(v[0] * (y + sy) >= (x * sy + a * y)){
    		first = 0;
    	}else if(v.back() * (y + sy) < (x * sy + a * y)){
    		first = 2 * n;
    	}else{
    		int L = 0;
    		int R = 2 * n;
    		int mid;
    		while(R - L > 1){
    			mid = (R + L) / 2;
    			if(v[mid] * (y + sy) < (x * sy + a * y)){
    				L = mid;
    			}else{
    				R = mid;
    			}
    		}
    		first = R;
    	}
    	if(v[0] * (y + sy) >= (x * sy + b * y)){
    		second = 0;
    	}else if(v.back() * (y + sy) < (x * sy + b * y)){
    		second = 2 * n;
    	}else{
    		int L = 0;
    		int R = 2 * n;
    		int mid;
    		while(R - L > 1){
    			mid = (R + L) / 2;
    			if(v[mid] * (y + sy) < (x * sy + b * y)){
    				L = mid;
    			}else{
    				R = mid;
    			}
    		}
    		second = R;
    	}
    	ld ans = 0;
    	if(first % 2 == 1){
    		ans += v[first] - aa;
    		++first;
    	}
    	if(second % 2 == 1){
    		ans += bb - v[second - 1];
    		--second;
    	}
    	first /= 2;
    	second /= 2;
    	ans += preflen[second] - preflen[first];
    	ans *= (y + sy) / ld(y);
    	cout << setprecision(18) << fixed << ans << endl;
    }
}