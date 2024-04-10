#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);

typedef long long int lint;
typedef long double ld;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    string s;

    cin >> n >> s;

    int d[] = {0,0};
    int total = 1;
    char last = s[0];
    FORR(i, 1, n)
    {
        if (s[i] != last)
        {
            last = s[i];
            total++;
        }

        if (s[i] == s[i-1])
        {
            d[i == '1']++;
        }
    }

    cout << total + max(min(d[0],2), min(d[1], 2));
}