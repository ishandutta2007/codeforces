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

    int n;
    cin >> n;
    string commands;
    cin >> commands;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        auto t = make_pair(0, 0);

        for (int j = i; j < n; j++)
        {
            char c = commands[j];
            if (c == 'U')
                t.first++;
            if (c == 'D')
                t.first--;
            if (c == 'R')
                t.second++;
            if (c == 'L')
                t.second--;

            if (t.first == 0 and t.second == 0) {
                count++;
            }
        }
    }

    cout << count << endl;
}