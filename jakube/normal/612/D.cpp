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


    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    FOR(i, n)
    {
        int s, t;
        cin >> s >> t;
        v.push_back(make_pair(s, 0));
        v.push_back(make_pair(t, 1));
    }
    sort(ALL(v));

    int current = 0;

    bool segment_started = false;
    int start = 0;

    vector<pair<int, int>> results;


    for (auto p : v)
    {
        if (p.second == 0)
        {
            current++;
            if (current == k)
            {
                start = p.first;
            }
        }
        else
        {
            current--;
            if (current == k - 1)
            {
                //if (start < p.first)
                //{
                    results.push_back(make_pair(start, p.first));
                //}
            }
        }
    }

    cout << results.size() << endl;
    for (auto p : results)
        cout << p.first << " " << p.second << endl;
}