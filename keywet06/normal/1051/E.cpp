#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi5;
typedef long long int64;

const int N = 1000005;
const int P = 998244353;

mt19937 Rand(std::chrono::steady_clock::now().time_since_epoch().count());

char tmp[N];
int P1, P2;
int G1, G2;
string A, L, R;
int pw1[N], pw2[N];
pi5 HA[N], HL[N], HR[N];
int dp[N];

void Read(string &s) {
    scanf("%s", tmp);
    s = tmp;
}

bool Prime(int x) {
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

void Compute(const string &X, pi5 H[]) {
    pi5 h = pi5(0, 0);
    for (int i = 0; i < X.size(); ++i) {
        h.first = (int64(h.first) * G1 + int64(X[i] - '0' + 1)) % P1;
        h.second = (int64(h.second) * G2 + int64(X[i] - '0' + 1)) % P2;
        H[i] = h;
    }
}

pi5 getHash(pi5 H[], int l, int r) {
    pi5 res = H[r];
    if (--l >= 0) {
        res.first = (int64(res.first) - int64(pw1[r - l]) * H[l].first % P1 + P1) % P1;
        res.second = (int64(res.second) - int64(pw2[r - l]) * H[l].second % P2 + P2) % P2;
    }
    return res;
}

bool LessEq(const string &A, pi5 HA[], int fromA, const string &B, pi5 HB[], int fromB, int len) {
    int l = 0, r = len - 1;
    while (l <= r) {
        int m = l + r >> 1;
        int ind1 = fromA + m;
        int ind2 = fromB + m;
        if (A[ind1] != B[ind2])
            r = m - 1;
        else if (getHash(HA, fromA, ind1) != getHash(HB, fromB, ind2))
            r = m - 1;
        else
            l = m + 1;
    }
    if (l >= len) return true;
    return A[fromA + l] < B[fromB + l];
}

int main() {
    P1 = uniform_int_distribution<int>(100000000, 1000000000)(Rand);
    P2 = uniform_int_distribution<int>(100000000, 1000000000)(Rand);
    G1 = uniform_int_distribution<int>(1000000, 10000000)(Rand);
    G2 = uniform_int_distribution<int>(1000000, 10000000)(Rand);
    while (!Prime(P1)) ++P1;
    while (!Prime(P2)) ++P2;
    while (!Prime(G1)) ++G1;
    while (!Prime(G2)) ++G2;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < N; ++i) {
        pw1[i] = int64(pw1[i - 1]) * G1 % P1;
        pw2[i] = int64(pw2[i - 1]) * G2 % P2;
    }
    Read(A);
    Read(L);
    Read(R);
    Compute(A, HA);
    Compute(L, HL);
    Compute(R, HR);
    dp[0] = 1;
    dp[1] = P - 1;
    int cur = 0;
    for (int i = 0; i < A.length(); ++i) {
        cur = (cur + dp[i]) % P;
        if (cur == 0) continue;
        if (A[i] == '0') {
            if (L.length() == 1 && L[0] == '0') {
                dp[i + 1] = (dp[i + 1] + cur) % P;
                dp[i + 2] = (dp[i + 2] - cur + P) % P;
            }
            continue;
        }
        int lef = L.length();
        int rig = min(int(R.length()), int(A.length()) - i);
        if (lef > rig) continue;
        if (!LessEq(L, HL, 0, A, HA, i, lef)) ++lef;
        if (lef > rig) continue;
        if (rig == R.length() && !LessEq(A, HA, i, R, HR, 0, rig)) rig--;
        if (lef > rig) continue;
        lef += i;
        rig += i;
        dp[lef] = (dp[lef] + cur) % P;
        dp[rig + 1] = (dp[rig + 1] - cur + P) % P;
    }
    cur = (cur + dp[A.length()]) % P;
    printf("%d\n", cur);
    return 0;
}