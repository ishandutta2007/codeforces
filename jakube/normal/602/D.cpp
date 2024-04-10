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

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    FOR(i, n)
        cin >> a[i];

    vector<int> diffs(n-1);
    FORR(i, 1, n)
        diffs[i-1] = abs(a[i] - a[i-1]);


    vector<int> left_bigger(n-1);
    stack<pair<int, int>> s;
    s.push(make_pair(INT_MAX, -1));
    FOR(i, n-1)
    {
        int diff = diffs[i];
        while (s.top().first < diff)
        {
            s.pop();
        }
        left_bigger[i] = abs(i - s.top().second);
        s.push(make_pair(diff, i));
    }

    vector<int> right_bigger(n-1);
    stack<pair<int, int>> s2;
    s2.push(make_pair(INT_MAX, n-1));
    for (int i = n-2; i >= 0; i--)
    {
        int diff = diffs[i];
        while (s2.top().first <= diff)
        {
            s2.pop();
        }
        right_bigger[i] = abs(i - s2.top().second);
        s2.push(make_pair(diff, i));
    }

    vector<pair<int, int>> queries(q);
    int l, r;
    FOR(i, q)
    {
        cin >> l >> r;
        queries[i] = make_pair(l, r);
    }

    for (auto const query : queries)
    {
        lint sum = 0;
        int last_best = 0;
        int last_index = -1;
        FOR(i, query.second - query.first )
        {
            int index = query.first + i - 1;
            l = min(left_bigger[index], i + 1);
            r = min(right_bigger[index], query.second - query.first - i);
            sum += 1LL * diffs[index] * l * r;
        }
        cout << sum << endl;
    }
}