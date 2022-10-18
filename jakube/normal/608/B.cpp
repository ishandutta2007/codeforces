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
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    string a, b;
    cin >> a >> b;

    //cout << a.length() << endl;
    //cout << b.length() << endl;

    lint count = 0;

    int count_zeros = 0;
    int count_ones = 0;

    for (int i = 0; i < b.length(); i++)
    {
        if (i < a.length())
        {
            if (a[i] == '1')
                count_ones++;
            else
                count_zeros++;
        }

        if (i > (b.length() - a.length()))
        {
            if (a[i - (b.length() - a.length()) - 1] == '1')
                count_ones--;
            else
                count_zeros--;
        }

        if (b[i] == '1')
            count += count_zeros;
        else
            count += count_ones;

    }

    cout << count;

}