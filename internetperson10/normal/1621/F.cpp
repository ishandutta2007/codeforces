#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll tot(ll zeroes, ll ones, ll bads, ll a, ll b, ll c) {
    //cout << zeroes << ' ' << ones << ' ' << bads << ' ' << a << ' ' << b << ' ' << c << '\n';
    if(zeroes > ones) return (ones+1)*a + (ones)*b - (bads)*c;
    return (zeroes)*a + (zeroes)*b - (bads)*c;
}

ll BIG = 1234567890;

ll solve(ll zeroes, ll ones, ll a, ll b, ll c, ll bl_in, ll bl_out, vector<ll> zero_ins) {
    bl_in = zero_ins.size();
    ll ans = 0;
    if(ones < 0) return -b;
    int i = 0;
    while(true) {
        if(i == bl_in) break;
        if(zero_ins[i] == 0) i++;
        else break;
    }
    if(i != bl_in) {
        while(ones) {
            ones--;
            zeroes--;
            zero_ins[i]--;
            ans += a;
            ans += b;
            if(zero_ins[i] == 0) i++;
            if(i == bl_in) break;
        }
    }
    bool end = false;
    ll best = ans;
    while(!end) {
        ones--;
        if(ones == -1) {
            if(i) {
                if(zeroes) best = max(best, ans+a);
                i--;
                ans += (b-c);
                ones++;
            }
            else {
                if(zeroes) ans += a;
                end = true;
            }
        }
        else {
            if(zeroes) {
                zeroes--;
                ans += a;
                ans += b;
            }
            else if(i) {
                ans += (b-c);
                i--;
                ones++;
            }
            else if(bl_out) {
                ans += (b-c);
                bl_out--;
            }
            else {
                end = true;
            }
        }
        best = max(best, ans);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n, a, b, c;
        ll best = 0, ans = 0;
        cin >> n >> a >> b >> c;
        string s; cin >> s;
        s.push_back('1' - s.back() + '0');
        int g = 0;
        vector<ll> nums;
        ll ones = 0;
        ll zeroes = 0;
        ll blocks_out = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') blocks_out = (s[0] == '0') + (s[n-1] == '0');
        }
        ll blocks_in = -blocks_out;
        vector<ll> zero_ins;
        for(int i = 0; i < n; i++) {
            if(s[i] != s[i+1]) {
                int len = i - g;
                if(s[i] == '0') {
                    zeroes += len; 
                    blocks_in++;
                    if(g != 0 && i != n-1) zero_ins.push_back(len);
                }
                else ones += len;
                g = i+1;
            }
        }
        sort(zero_ins.begin(), zero_ins.end());
        cout << max(solve(zeroes, ones, a, b, c, blocks_in, blocks_out, zero_ins),
                solve(zeroes, ones-1, a, b, c, blocks_in, blocks_out, zero_ins)+b) << '\n';
    }
}