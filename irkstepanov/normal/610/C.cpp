#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef unsigned int uuint;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll inf = static_cast<ll>(1e18);

string rev(const string& s)
{
    string t = s;
    for (int i = 0; i < sz(t); ++i) {
        if (t[i] == '+') {
            t[i] = '*';
        } else {
            t[i] = '+';
        }
    }
    return t;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int k;
    cin >> k;

    if (k == 0) {
        cout << "+\n";
        return 0;
    }

    vector<string> v;
    v.pb("++");
    v.pb("+*");

    for (int i = 2; i <= k; ++i) {
        int x = sz(v);
        vector<string> vNew(x * 2);
        int pos = 0;
        for (int j = 0; j < x; ++j) {
            string s = v[j];
            vNew[pos++] = s + s;
            string t = rev(s);
            vNew[pos++] = s + t;
        }
        v.swap(vNew);
    }

    for (int i = 0; i < sz(v); ++i) {
        cout << v[i] << "\n";
    }

}