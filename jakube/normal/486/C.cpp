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
template <typename T, typename S>
void DBG(pair<T, S> p){if(debug)cout<<p.first<<" "<<p.second<<endl;}
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n, p;
    string s;
    cin >> n >> p >> s;

    int count = 0;
    FOR(i, n/2) {
        int t = abs(s[i] - s[n - 1 - i]);
        count += min(t, 26-t);
    }

    if (p > n / 2)
        p = n - p;
    else
        p--;

    int left = 0;
    int right = 0;

    int i = 0;
    while (p + 1 + i < n/2)
    {
        i++;
        if (s[p+i] != s[n-1-p-i])
            right = i;
    }
    i = 0;
    while (p + i - 1 >= 0)
    {
        i--;
        if (s[p+i] != s[n-1-p-i])
            left = i;
    }

    left *= -1;
    DBG(count + left + right + min(left, right));
}