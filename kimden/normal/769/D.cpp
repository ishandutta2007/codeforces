#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, k;
vector<int> cnt;
vector<int> v;
vector<int> perm;
const int MAXN = 10001;
const int DEG = 14;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    cnt.resize(1 << DEG + 1, 0);
    int a;
    for(int i = 0; i < n; ++i){
        cin >> a;
        cnt[a]++;
    }
    ll ans = 0;
    if(k == 0){
        for(int i = 0; i < MAXN; ++i){
            ans += (cnt[i] * 1LL * (cnt[i] - 1)) / 2;
        }
        cout << ans << endl;
    }else{
        v.clear();
        for(int i = 0; i < DEG; ++i){
            if(DEG - i <= k){
                v.push_back(1);
            }else{
                v.push_back(0);
            }
        }
        do {
            int cur = 0;
            for(int i = 0; i < DEG; ++i){
                cur <<= 1;
                cur += v[i];
            }
            perm.push_back(cur);
        }while(next_permutation(v.begin(), v.end()));
        for(int i = 0; i < MAXN; ++i){
            if(cnt[i]) {
                for (auto x: perm) {
                    int x1 = i;
                    int x2 = x1 ^ x;
                    ans += cnt[x1] * 1LL * cnt[x2];
                }
            }
        }
        ans >>= 1;
        cout << ans << endl;
    }
}