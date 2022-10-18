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

    lint n, b, t, number1 = 0, number2 = 0;
    cin >> n >> b;
    vector<lint> v1, v2;
    FOR(i, n)
    {
        cin >> t;
        v1.push_back(t);
    }
    for(int i : v1)
        number1 = number1*b + i;

    cin >> n >> b;
    FOR(i, n)
    {
        cin >> t;
        v2.push_back(t);
    }
    for(int i : v2)
        number2 = number2*b + i;

    if (number1 == number2)
        cout << "=";
    else
        cout << (number1 < number2 ?"<":">");
}