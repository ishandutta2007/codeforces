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

    int n, m;
    cin >> n >> m;

    int max_height = INT_MAX;
    for (int k = 0; k <= min(n, m); k++)
    {
        int B = m + k;
        int b = B*3;

        int taken = b/6 - k;
        int unter = b/2 - taken;


        if (unter >= n)
        {
            max_height = min(max_height, b);
            //cout << b << ", unter=" << unter << endl;
        }
        else
        {
            int a = (b/2)*2 + (n - unter)*2;
            max_height = min(max_height, a);
            //cout << b << ", a=" << a << endl;
        }
    }

    cout << max_height;
}