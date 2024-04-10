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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    vector<int> v(5), w(5);
    FOR(i,5)
        cin >> v[i];
    FOR(i,5)
        cin >> w[i];
    int s, u;
    cin >> s >> u;

    double score = 0;
    FOR(i, 5)
    {
        int x = 500*(i+1);
        score += max(0.3*x, (1 - v[i]/250.0)*x - 50*w[i]);
    }
    cout << (int)(score + s*100 - u*50+0.5) << endl;

}