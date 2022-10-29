#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
    ll x, y;
    node() {}
    node(ll a, ll b) : x(a), y(b) {}
    void put() { cout << x << ' ' << y << endl; }
};
node operator+(node a, node b) { return node(a.x + b.x, a.y + b.y); }
node operator-(node a, node b) { return node(a.x - b.x, a.y - b.y); }
ll operator*(node a, node b) { return a.x * b.x + a.y * b.y; }
ll operator^(node a, node b) { return a.x * b.y - a.y * b.x; }
node a[10000], b[10000];
bool cmp(node a, node b) { return a.x < b.x || a.x == b.x && a.y < b.y; }
ll andrew(ll n) {
    sort(a + 1, a + 1 + n, cmp);
    int top = 0;
    for (int i = 1; i <= n; i++) {
        while (top > 1 && ((b[top] - b[top - 1]) ^ (a[i] - b[top - 1])) <= 0)
            --top;
        b[++top] = a[i];
    }
    int tem = top;
    for (int i = n - 1; i > 0; i--) {
        while (top > tem && ((b[top] - b[top - 1]) ^ (a[i] - b[top - 1])) <= 0)
            --top;
        b[++top] = a[i];
    }
    if (n > 1) --top;
    return top;
}
int main() {
    ios::sync_with_stdio(false);
    ll n;
    double s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    ll k = andrew(n);
    ll mmax = -1;

    node m[3];
    for (int i = 0; i < k; i++) b[i] = b[i + 1];
    for (int i = 0; i < k; i++) {
        int p = (i + 2) % k;
        for (int j = 1; j < k - 1; j++) {
            while (abs((b[i] - b[(p + 1) % k]) ^
                       (b[(i + j) % k] - b[(p + 1) % k])) >
                   abs((b[i] - b[p]) ^ (b[(i + j) % k] - b[p])))
                p = (p + 1) % k;
            if (abs((b[i] - b[p]) ^ (b[(i + j) % k] - b[p])) > mmax) {
                mmax = abs((b[i] - b[p]) ^ (b[(i + j) % k] - b[p]));
                m[0] = b[i];
                m[1] = b[(i + j) % k];
                m[2] = b[p];
            }
        }
    }
    (m[0] + m[1] - m[2]).put();
    (m[1] + m[2] - m[0]).put();
    (m[2] + m[0] - m[1]).put();
}