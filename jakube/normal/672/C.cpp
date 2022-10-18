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


double dist(pair<int, int> start, pair<int, int> end)
{
    return pow(pow(start.first-end.first, 2) + pow(start.second-end.second, 2), 0.5);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    pair<int, int> a, b, t;
    cin >> a.first >> a.second >> b.first >> b.second >> t.first >> t.second;
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    FOR(i, n) cin >> v[i].first >> v[i].second;
    
    double total = 0.0;
    vector<double> dists(n);
    vector<pair<double, int>> dist_a(n), dist_b(n);
    FOR(i, n)
    {
        dists[i] = dist(t, v[i]) * 2;
        total += dists[i];
        dist_a[i] = {dist(t, v[i]) + dist(a, v[i]) - dists[i], i};
        dist_b[i] = {dist(t, v[i]) + dist(b, v[i]) - dists[i], i};
    }
    
    sort(ALL(dist_a));
    sort(ALL(dist_b));

    double best = 1e20;
    FOR(i, min(5, n)) FOR(j, min(5, n)) if (dist_a[i].second != dist_b[j].second)
        best = min(best, total + dist_a[i].first + dist_b[j].first);

    FOR(i, n)
    {
        best = min(best, total + dist_b[i].first);
        best = min(best, total + dist_a[i].first);
    }

    cout << best << endl;
}