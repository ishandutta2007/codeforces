#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e5;
const long double pi = 3.14159265358979323846;


int main() {
    int i, j, n, k;
    long double r;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> r;
    long double alpha = cos(2.0 * pi / n);
    long double a = 1 + alpha, b = 2 * r * alpha - 2 * r, c = r * r * (alpha - 1);
    long double D = b * b - 4 * a * c;
    cout << fixed << setprecision(15) << (sqrt(D) - b) / (2 *a) << endl;
}