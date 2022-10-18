#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);

typedef long long int lint;
typedef long double ld;

lint modpow(lint base, lint exp, lint modulus) {
    base %= modulus;
    lint result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

int grundy(int i, int k)
{
    if (k % 2 == 0)
    {
        if (i < 3)
            return i;
        return 1 - (i%2);
    }
    else
    {
        if (i < 4)
            return i%2;
        if (i == 4)
            return 2;
        if (i%2)
            return 0;
        return grundy(i / 2, k) == 1 ? 2 : 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    FOR(i, n)
        cin >> v[i];

    int result = 0;
    for (auto i : v)
        result ^= grundy(i, k);

    if (result)
        cout << "Kevin";
    else
        cout << "Nicky";

}