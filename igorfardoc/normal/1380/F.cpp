#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 998244353;
int dp[500000][10];
struct Node {
    int l1;
    int r1;
    int lvalue;
    int ans;
};
Node t[2000007];

int bin_pow(int a, int b) {
    if(b == 0) {
        return 1;
    }
    int res = bin_pow(a, b >> 1);
    res = ((ll)res * res) % mod;
    if(b & 1) {
        res = ((ll)res * a) % mod;
    } 
    return res;
}

int obr(int a) {
    return bin_pow(a, mod - 2);
}




Node join(Node a, int lena, Node b, int lenb) {
    Node res;
    res.l1 = a.l1;
    if(a.l1 == lena) {
        res.l1 += b.l1;
    }

    res.r1 = b.r1;
    if(b.r1 == lenb) {
        res.r1 += a.r1;
    }

    if(a.lvalue != -1) {
        res.lvalue = a.lvalue;
    } else {
        res.lvalue = b.lvalue;
    }

    int ans1 = a.ans;
    if(a.r1 != 0) {
        ans1 = ((ll)ans1 * obr(dp[a.r1 - 1][1])) % mod;
    }
    int ans2 = b.ans;
    if(b.lvalue == -1) {
        ans2 = ((ll)ans2 * obr(dp[b.l1 - 1][1])) % mod;
    } else {
        ans2 = ((ll)ans2 * obr(dp[b.l1][b.lvalue])) % mod;
    }
    int am1 = a.r1 + b.l1;
    int d = b.lvalue;
    if(d == -1) {
        --am1;
        d = 1;
    }
    res.ans = (ll)ans1 * ans2 % mod * dp[am1][d] % mod;
    return res;
}


void build_tree(int now, int l, int r, string& s) {
    if(l == r) {
        if(s[l] == '1') {
            t[now].r1 = 1;
            t[now].l1 = 1;
            t[now].ans = 2;
            t[now].lvalue = -1;
        } else {
            t[now].lvalue = s[l] - '0';
            t[now].ans = (s[l] - '0') + 1;
            t[now].l1 = 0;
            t[now].r1 = 0;
        }
        return;
    }
    int mid = (l + r) / 2;
    build_tree(now * 2, l, mid, s);
    build_tree(now * 2 + 1, mid + 1, r, s);
    t[now] = join(t[now * 2], mid - l + 1, t[now * 2 + 1], r - mid);
}

void update(int now, int l, int r, int pos, int d) {
    if(l == r) {
        if(d == 1) {
            t[now].r1 = 1;
            t[now].l1 = 1;
            t[now].ans = 2;
            t[now].lvalue = -1;
        } else {
            t[now].lvalue = d;
            t[now].ans = d + 1;
            t[now].l1 = 0;
            t[now].r1 = 0;
        }
        return;
    }
    int mid = (l + r) / 2;
    if(mid >= pos) {
        update(now * 2, l, mid, pos, d);
    } else {
        update(now * 2 + 1, mid + 1, r, pos, d);
    }
    t[now] = join(t[now * 2], mid - l + 1, t[now * 2 + 1], r - mid);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    int n, m;
    cin >> n >> m;
    cin >> s;
    for(int i = 0; i < n; i++) {
        for(int d = 0; d < 10; d++) {
            if(i == 0) {
                dp[i][d] = d + 1;
                continue;
            }
            dp[i][d] = ((ll)dp[i - 1][1] * (d + 1)) % mod;
            int need = 1;
            if(i != 1) {
                need = dp[i - 2][1];
            }
            dp[i][d] = ((ll)need * (9 - d) + dp[i][d]) % mod;
        }
    }
    build_tree(1, 0, n - 1, s);
    //cout << t[1].ans << '\n';
    for(int o = 0; o < m; o++) {
        int pos, d;
        cin >> pos >> d;
        --pos;
        update(1, 0, n - 1, pos, d);
        cout << t[1].ans << '\n';
    }
}