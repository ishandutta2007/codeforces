#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int t;
    cin >> t;
    string s;
    for(int i = 0; i < t; ++i){
        cin >> s;
        int n = s.length();
        vector<int> v(n + 1);
        v[0] = 0;
        for(int j = 0; j < n; ++j){
            v[j + 1] = v[j] ^ (1 << (s[j] - '0'));
        }
        int idx = -1;
        for(int j = n - 1; j >= 0; --j){
            int u = __builtin_popcount(v[j]);
            if((j > 0 && s[j] != '0') || (j == 0 && s[j] != '1')){
                if(u < n - j || (u <= n - j && __builtin_popcount(v[j] & ((1 << (s[j] - '0')) - 1)) >= 1)){
                    idx = j;
                    break;
                }
            }
        }
        if(idx == -1){
            for(int j = 0; j < n - 2; ++j){
                cout << "9";
            }
            cout << endl;
        }else{
            int val = v[idx];
            int u = __builtin_popcount(val);
            if(u < n - idx){
                vector<int> dig;
                --s[idx];
                val ^= (1 << (s[idx] - '0'));
                ++idx;
                for(int j = 9; j >= 0; --j){
                    if(val & (1 << j)){
                        dig.push_back(j);
                        val ^= (1 << j);
                    }
                }
                sort(dig.rbegin(), dig.rend());
                int rig = n;
                while(!dig.empty()){
                    s[--rig] = char('0' + dig.back());
                    dig.pop_back();
                }
                for(; idx < rig; ++idx){
                    s[idx] = '9';
                }
            }else{
                int o = (val & ((1 << (s[idx] - '0')) - 1));
                for(int j = 9; j >= 0; --j){
                    if(o & (1 << j)){
                        s[idx] = char('0' + j);
                        val ^= (1 << j);
                        ++idx;
                        break;
                    }
                }
                for(int j = 9; j >= 0; --j){
                    if(val & (1 << j)){
                        s[idx++] = char('0' + j);
                        val ^= (1 << j);
                    }
                }
            }
            cout << s << endl;
        }
    }



}