#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <llint, llint> pi;
typedef vector <llint> vi;

int sol;
vector < pair <pi, int> > v;

void mult (llint x, llint n) {
    if (n <= 1) return;
    mult(x, n / 2);
    v.push_back({{(n/2) * x, (n/2) * x}, 0});
    if (n & 1) v.push_back({{x, (n - 1) * x}, 0});
}

llint gcd (llint a, llint b, llint& x, llint& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    llint x1, y1;
    llint d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

llint get_gcd (llint a, llint b) {
    mult(b, 2);
    b *= 2;
    //cout << "a i b " << a << " " << b << endl;
    llint x = 0, y = 0;
    llint d = gcd(a, b, x, y);
    x += 2 * b;
    y -= 2 * a;
    x = abs(x); y = abs(y);
    mult(a, x);
    mult(b, y);
    v.push_back({{a * x, b * y}, 1});
    return (a * x) ^ (b * y);
}

void ispis () {
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first.first << " " << (v[i].second == 0 ? '+' : '^') << " " << v[i].first.second << '\n';
    }
}

void solve (llint x) {
    while (x > 1) {
        for (int i = 1; i <= 25; i++) {
            if (__gcd(x, (x * (1 << i)) ^ x) < x) {
                mult(x, (1 << i));
                v.push_back({{x, x * (1 << i)}, 1});
                x = get_gcd(x, (x * (1 << i)) ^ x);
                break;
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int val; cin >> val;
    v.push_back({{val, val}, 1});
    solve(val);
    ispis();
    return 0;
}