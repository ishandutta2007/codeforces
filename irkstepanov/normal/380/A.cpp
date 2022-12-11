#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <queue>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const ll mod = 1e9 + 7;
const int inf = 100500;

struct query
{
    int type;
    int a, b;
};

int main()
{

    //ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("mine.txt");

    int n;
    cin >> n;

    vector<query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == 1) {
            cin >> queries[i].a;
        } else {
            cin >> queries[i].a >> queries[i].b;
        }
    }

    int q;
    cin >> q;
    vector<ll> p(q);

    for (int i = 0; i < q; ++i) {
        cin >> p[i];
    }

    vector<int> pref;
    ll len = 0;
    int add = 0, get = 0;

    while (get < q) {
        //cout << get << " " << add << "\n";
        if (queries[add].type == 1) {
            if (sz(pref) < inf) {
                pref.pb(queries[add].a);
            }
            ++len;
            if (len == p[get]) {
                cout << queries[add].a << " ";
                ++get;
            }
            ++add;
        } else {
            if ((ll)(len) + (ll)(queries[add].a) * (ll)(queries[add].b) >= p[get]) {
                ll k = (p[get] - len + queries[add].a - 1) / queries[add].a;
                ll r = p[get] - len - (k - 1) * queries[add].a - 1;
                cout << pref[r] << " ";
                ++get;
            }
            if (get < q && (ll)(len) + (ll)(queries[add].a) * (ll)(queries[add].b) < p[get]) {
                len += (ll)(queries[add].a) * (ll)(queries[add].b);
                int curr = 0, done = 0;
                while (sz(pref) < inf && done < queries[add].b) {
                    pref.pb(pref[curr]);
                    ++curr;
                    if (curr == queries[add].a) {
                        curr = 0;
                        ++done;
                    }
                }
                ++add;
            }
        }
    }

}