#include <bits/stdc++.h>
#define int long long
using namespace std;
 
pair<int, int> extgcd(int a, int b) {
       if(!b) return {1, 0};
    pair<int, int> val = extgcd(b, a % b);
    return {val.second, val.first - (a / b) * val.second};
}

int crt(int a, int m, int b, int n) {
	if (n > m) swap(a, b), swap(m, n);
	pair<int, int> val = extgcd(m, n);
	int x = val.first, y = val.second, g = __gcd(m, n);
	assert((a - b) % g == 0);
	x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m*n/g : x;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    map<int, int> pos;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        pos[a[i]] = i + 1;
    }
    int gcd = __gcd(n, m);
    int ans = k;
    vector<int> s;
    for(int j = 0; j < m; ++j){
        cin >> b[j];
        if(pos[b[j]]){
            int x = pos[b[j]] - 1, y = j;
            if((x - y) % gcd == 0){
	            s.push_back(crt(x, n, y, m) + 1);
	        }
        }
    }
    sort(s.begin(), s.end());
    int rep = n / gcd * m;
    int l = k, r = (int)1e18, mid;
    while(l < r){
        mid = (l + r) >> 1;
        int val = k;
        for(int i = 0; i < (int)s.size(); ++i){
            if(s[i] <= mid){
                val += 1 + (mid - s[i]) / rep;
            }
        }
        if(val <= mid){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}