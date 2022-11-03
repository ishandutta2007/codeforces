#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define X first
#define Y second


string dict = "RPS";
const int N = 2e5 + 10;
int n, test;
int a[N];
set<int> mset[3];

int convert(char ch) {
    int ans = 0;
    while (dict[ans] != ch) ans++;
    return ans;
}


struct BIT{
    int a[N];
    void add(int x, int v) {
        while (x < N) {
            a[x] += v;
            x += x & -x;
        }
    }
    int get(int x) {
        int ans = 0;
        while (x) {
            ans += a[x];
            x -= x & -x;
        }
        return ans;
    }
}mbit[3];
void prepare() {
    string s;
    cin >> n >> test >> s;
    for(int i = 1; i <= n; i++) 
         a[i] = convert(s[i - 1]);
    
    for(int i = 1; i <= n; i++) {
        mset[a[i]].insert(i);
        mbit[a[i]].add(i, 1);
    }
}
void modified(int pos, int ch) {
    mset[a[pos]].erase(pos);
    mbit[a[pos]].add(pos, -1);
    a[pos] = ch;
    mset[a[pos]].insert(pos);
    mbit[a[pos]].add(pos, 1);
}
int solve() {
    int ans = 0;
    for(int use = 0; use < 3; use++) {
        int anti = (use + 1) % 3, ally = (use + 2) % 3;
        if (mbit[anti].get(n) == 0) {
            ans += mbit[use].get(n);
            continue;
        }
        if (mbit[ally].get(n) == 0) continue;
        int aL = *mset[ally].begin(), aR = *mset[ally].rbegin();
        int antiL = *mset[anti].begin(), antiR = *mset[anti].rbegin();

        int midR = min(antiR, aR), midL = max(aL, antiL);

        ans += mbit[use].get(min(antiL, aR))
            + mbit[use].get(n) - mbit[use].get(max(aL, antiR));
        if (midL <= midR) {
            ans += mbit[use].get(min(antiR, aR)) - mbit[use].get(max(aL, antiL));
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prepare();
    
    cout << solve() << '\n';
    while (test--) {
        int pos; char ch;
        cin >> pos >> ch;
        modified(pos, convert(ch));
        cout << solve() << '\n';
    }
}