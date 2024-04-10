#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);
const long long int MOD = 1e9 + 7;

typedef long long int lint;
typedef long double ld;
lint powmod(lint a,lint b, lint mod) {lint res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

const int debug = 1;
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    lint n;
    cin >> n;

    //FOR(i, 100) {
    //    n = i;
        lint l = 0;
        lint r = 1e9;
        lint m;

        FOR(i, 1000) {
            m = (l + r) / 2;

            lint result = 3LL * m * (m + 1);
            if (result > n)
                r = m;
            else
                l = m;
        }

        lint number = l;
        lint N = n;
        n -= 3LL * number * (number + 1);

        //cout << number << " " << n << endl;
        number += 1;

        lint x, y;
        if (N == 1)
        {
            x = 1;
            y = 2;
        }
        else if (N == 2)
        {
            x = -1;
            y = 2;
        }
        else if (n < number)
        {
            if (n < 2)
                x = 2 * (number - 1) + n;
            else
                x = 2 * (number - 1) + 1 - (n - 1);
            y = 2 * n;
        }
        else if (n < 2 * number) {
            x = 2 * (number - 1) + number - 2 * (n - number + number -1);
            y = 2 * number;
        }
        else if (n < 3 * number) {
            x = 2 * (number - 1) + number - 2 * (number + number - 1);
            y = 2 * number;

            x -= (n - 2 * number);
            y -= 2 * (n - 2 * number);
        }
        else if (n < 4 * number) {
            x = -2 * number;
            y = 0;

            x += (n - 3 * number);
            y -= 2 * (n - 3 * number);

        }
        else if (n < 5 * number) {
            x = -2 * number + number + 2 * (n - 4 * number);
            y = -2 * number;
        }
        else {
            x = number + (n - 5 * number);
            y = -2 * number + 2 * (n - 5 * number);
        }

        cout << x << " " << y << endl;
    //}
}