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


lint dist(pair<lint,lint> A, pair<lint,lint> B)
{
    return (A.first-B.first)*(A.first-B.first) + (A.second-B.second)*(A.second-B.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    pair<lint, lint> W1, W2;
    cin >> n >> W1.first >> W1.second >> W2.first >> W2.second;

    vector<pair<lint,lint>> flowers(n);
    FOR(i, n)
        cin >> flowers[i].first >> flowers[i].second;

    flowers.push_back(W1);
    flowers.push_back(W2);

    lint best = 9223372036854775807LL;
    for (auto q : flowers)
    {
        lint r1 = dist(q, W1);
        lint r2 = 0;

        for(auto p: flowers)
        {
            lint d = dist(p, W1);
            if (d > r1)
            {
                r2 = max(r2, dist(p, W2));
            }
        }

        best = min(best, r1+r2);
    }

    cout << best;
}