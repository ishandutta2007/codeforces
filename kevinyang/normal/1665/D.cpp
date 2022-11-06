#include <bits/stdc++.h>
using namespace std;
#define int long long
int safe_mod(int x, int m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}
pair<int,int> inv_gcd(int a, int b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};
    int s = b, t = a;
    int m0 = 0, m1 = 1;
    while (t) {
        int u = s / t;
        s -= t * u;
        m0 -= m1 * u;
        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}
pair<int,int> crt(const vector<int>& r, const vector<int>& m) {//if p.second == 0 then there is no answer 
    assert(r.size() == m.size());
    int n = (int)(r.size());
    int r0 = 0, m0 = 1;
    for (int i = 0; i < n; i++) {
        assert(1 <= m[i]);
        int r1 = safe_mod(r[i], m[i]), m1 = m[i];
        if (m0 < m1) {
            swap(r0, r1);
            swap(m0, m1);
        }
        if (m0 % m1 == 0) {
            if (r0 % m1 != r1) return {0, 0};
            continue;
        }
        int g, im;
        tie(g, im) = inv_gcd(m0, m1);
        int u1 = (m1 / g);
        if ((r1 - r0) % g) return {0, 0};
        int x = (r1 - r0) / g % u1 * im % u1;
        r0 += x * m0;
        m0 *= u1;
        if (r0 < 0) r0 += m0;
    }
    return {r0, m0};
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<int>primes = {2,3,5,7,11,13,17,19,23};
    int prod = 1;
    for(int nxt: primes){
    	prod*=nxt;
    }
    int t;
    cin >> t;
    while(t--){
    	vector<int>rem(9);
    	for(int i = 0; i<23; i++){
    		vector<int>r(9);
    		for(int j = 0; j<9; j++){
    			r[j] = i%primes[j];
    		}
    		pair<int,int>p = crt(r,primes);
    		assert(p.second!=0);
    		assert(p.first<=(int)2e9);
    		if(p.first==0)p.first+=prod;
    		cout << "? " << p.first << " " << p.first+prod << endl;
    		int v;
    		cin >> v;
    		for(int j = 0; j<9; j++){
    			if(v%primes[j]==0){
    				int realr = primes[j]-r[j];
    				realr%=primes[j];
    				rem[j] = realr;
    			}
    		}
    	}
    	pair<int,int>p = crt(rem,primes);
    	assert(p.second!=0);
    	for(int i = 4; i>=0; i--){
    		int val = i*prod+p.first;
    		if(val>(int)1e9)continue;
    		cout << "? " << val << " " << val*2 << endl;
    		int v;
    		cin >> v;
    		if(v==val){
    			cout << "! " << val << endl;
    			break;
    		}
    	}
    }
    return 0;
}