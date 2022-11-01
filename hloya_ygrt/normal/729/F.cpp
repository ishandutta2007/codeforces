#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef uint8_t u8;

const u16 N = 4004;
const u16 M = 90;

int a[N];
int smf[N];
int*const sum = smf + 1;
u16 n;

//map<tuple<int, int, int>, int> m;
unordered_map<u32, int> m;

const int INF = 1e9;

int solve(u16 l, u16 r, u16 k) {
    //u32 ad = l + ((u32)r << 12) + ((u32)k << 24);
    u32 ad = l + (r << 12) + (k << 24);
    if (m.count(ad)) return m[ad];
    u32 len = (l > r ? l - r : r - l) + 1;
    if (l > r) {
        if (len == k) {
            return m[ad] = sum[l] - sum[l - k] - (len - k < k ? 0 : solve(r, l - k, k));
        }
        return m[ad] = max(sum[l] - sum[l - k] - (len - k < k ? 0 : solve(r, l - k, k)),
        sum[l] - sum[l - k - 1] - (len - k - 1 < k + 1 ? 0 : solve(r, l - k - 1, k + 1)));
    } else {
        if (len == k) {
            return m[ad] = sum[l + k - 1] - sum[l - 1] - (len - k < k ? 0 : solve(r, l + k, k));
        }
        return m[ad] = max(sum[l + k - 1] - sum[l - 1] - (len - k < k ? 0 : solve(r, l + k, k)),
        sum[l + k] - sum[l - 1] - (len - k - 1 < k + 1 ? 0 : solve(r, l + k + 1, k + 1)));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    cin >> n;
    //n = 4000;
    //m.reserve(8000000);
    m.rehash(6.0e7);
    //for (int i = 0; i < M; i++) m[i].rehash(150000);
    for (u16 i = 0; i < n; i++) {
        cin >> a[i];
        //a[i] = 123 + i;
    }  
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }
    sum[-1] = 0;
    for (u16 i = 0; i < n; i++) sum[i] = sum[i - 1] + a[i];
    cout << solve(0, n - 1, 1) << endl;
    //cerr << wow << endl;
    //cerr << sada << endl;
    return 0;
}