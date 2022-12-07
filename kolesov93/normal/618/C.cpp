#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);
int n;
const int N = 100111;

struct cell {
    ll x, y;
    int id;
} a[N];

ll mul(const cell& A, const cell& B) {
    return A.x * B.y - A.y * B.x;
}

bool cmp(const cell& A, const cell& B) {
    ll val = mul(A, B);
    if (val != 0) return val < 0;
    return A.x * A.x + A.y * A.y < B.x * B.x + B.y * B.y;
}

int main() {
    scanf("%d", &n); 
    for (int i = 0; i < n; ++i) {
        int X, Y;
        scanf("%d%d", &X, &Y);
        a[i].x = X;
        a[i].y = Y;
        a[i].id = i + 1;
    }
    for (int i = 1; i < n; ++i) {
        if (a[i].x < a[0].x || (a[i].x == a[0].x && a[i].y < a[0].y)) {
            swap(a[i], a[0]);
        }
    }

    for (int i = 1; i < n; ++i) {
        a[i].x -= a[0].x;
        a[i].y -= a[0].y;
    }
    a[0].x = a[0].y = 0;

    sort(a + 1, a + n, cmp);
    cout << a[0].id << " " << a[1].id << " ";
    for (int i = 2; i < n; ++i) {
        if (mul(a[1], a[i]) != 0) {
            cout << a[i].id << endl;
            break;
        }
    }

    return 0;
}