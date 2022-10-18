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

const int debug = 0;
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    lint a, b;
    cin >> a >> b;

    // convert each number
    int len_a = ceil(log2(a + 1));
    int len_b = ceil(log2(b + 1));

    DBG(len_a);
    DBG(len_b);

    int count = 0;
    FORR(length, len_a, len_b + 1)
    {
        lint tmpl = (1LL << (length)) - 1;
        DBG(tmpl);
        DBG("");
        FOR(i, length - 1)
        {
            lint number = tmpl ^ (1LL << i);

            DBG(number);
            if (a <= number && number <= b) {
                count++;

            }
        }

    }

    cout << count;
}