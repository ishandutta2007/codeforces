#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<ll> MOD = {1000000007, 1000000009, 1000000021, 694201337};
vector<vector<ll>> pow29;

int SIZE = 1000001;

struct StringHash {
    string s;
    vector<vector<ll>> hash;
    StringHash(string s2) {
        s = s2;
        hash.resize(MOD.size());
        for(int i = 0; i < MOD.size(); i++) {
            hash[i].resize(s.size());
            hash[i][0] = s[0] - 'a' + 1;
            for(int j = 1; j < s.size(); j++) {
                hash[i][j] = (pow29[i][j] * (s[j] - 'a' + 1) + hash[i][j-1]) % MOD[i];
            }
        }
    }
    ll ha(int i) {
        return hash[i][s.size() - 1];
    }
    ll subHash(int i, int l, int len) {
        if(l == 0) return hash[i][len-1];
        return (hash[i][l+len-1] - hash[i][l-1] + MOD[i]) % MOD[i];
    }
    bool isSub(int i, int j, int len) {
        assert(max(i, j) + len <= s.size());
        if(i > j) swap(i, j);
        for(int k = 0; k < MOD.size(); k++) {
            if((pow29[k][j-i] * subHash(k, i, len))%MOD[k] != subHash(k, j, len)) return false;
        }
        return true;
    }
};

void precomp() {
    pow29.resize(MOD.size());
    for(int i = 0; i < MOD.size(); i++) {
        ll k = 1;
        pow29[i].resize(SIZE);
        for(int j = 0; j < SIZE; j++) {
            pow29[i][j] = k;
            k *= 29;
            k %= MOD[i];
        }
    }
}

int main() {
    precomp();
    string s, t;
    cin >> s >> t;
    int a = 0, b = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s.at(i) == '0') a++;
        else b++;
    }
    StringHash str(t); 
    int ans = 0;
    for(int x = 1; x < t.size(); x++) {
        int y = (t.size() - a * x)/b;
        if(y <= 0) break;
        if(a * x + b * y == t.size()) {
            bool ok = true; 
            int g = 0;
            int ze = -1, on = -1;
            for(int j = 0; j < s.size(); j++) {
                if(s.at(j) == '0') {
                    if(ze == -1) ze = g;
                    if(str.isSub(g, ze, x) == false) ok = false; 
                    g += x;
                }
                else {
                    if(on == -1) on = g;
                    if(str.isSub(g, on, y) == false) ok = false;
                    g += y;
                }
            }
            if(x == y) {
                if(t.substr(ze, x) == t.substr(on, y)) ok = false;
            }
            if(ok) ans++;
        }
    }
    cout << ans << '\n';
}