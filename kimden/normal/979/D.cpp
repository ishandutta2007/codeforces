#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

void inc(vector<int>& f, int idx){
    while(idx < f.size()){
        ++f[idx];
        idx = idx | (idx + 1);
    }
}

int pref(vector<int>& f, int idx){ // including
    int sum = 0;
    while(idx >= 0){
        sum += f[idx];
        idx = (idx & (idx + 1)) - 1;
    }
    return sum;
}

const int Z = 316;
const int M = (1 << 17) + 6;

int main() {
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    vector<vector<int>> fen(Z);
    for(int i = 0; i < Z; ++i){
        fen[i].resize((M + i) / (i + 1) + 3, 0);
    }
    vector<int> cnt(M, 0);
    int x, s, k;
    for(int i = 0; i < q; ++i){
        int type;
        cin >> type;
        if(type == 1){
            cin >> x;
            if(!cnt[x]) {
                cnt[x] = 1;
                for (int i = 0; i < Z; ++i) {
                    if (x % (i + 1) == 0) {
                        inc(fen[i], x / (i + 1));
                    }
                }
            }
        }else{
            cin >> x >> k >> s;
            if(x % k != 0){
                cout << -1 << endl;
                continue;
            }
            if(k > Z){
                pii ans = {-1, -1};
                for(int i = 0; i <= 100000 && i <= s - x; i += k){
                    if(cnt[i]){
                        ans = max(ans, {x ^ i, i});
                    }
                }
                cout << ans.second << endl;
                continue;
            }
            int countnums = pref(fen[k - 1], (s - x) / k);
            if(countnums == 0){
                cout << -1 << endl;
                continue;
            }
            int L = 0, R = (1 << 17), bound = ((s - x) / k) * k;
            int ans = 0;
            bool ex = 0;
            for(int b = (1 << 16); b > 0; b >>= 1){
                if(L > bound){
                    cout << -1 << endl;
                    ex = 1;
                    break;
                }
                int mid = (L + R) >> 1;
                if(mid > bound){
                    R = mid;
                    continue;
                }
                if(x & b){
                    int cnt0 = pref(fen[k - 1], (mid - 1) / k) - pref(fen[k - 1], (L - 1) / k);
                    if(cnt0 == 0){
                        L = mid;
                    }else{
                        R = mid;
                    }
                }else{
                    int cnt0 = pref(fen[k - 1], (min(R, bound + 1) - 1) / k) - pref(fen[k - 1], (mid - 1) / k);
                    if(cnt0 == 0){
                        R = mid;
                    }else{
                        L = mid;
                    }
                }
            }
            if(ex){
                continue;
            }
            cout << L << endl;
        }
    }
}