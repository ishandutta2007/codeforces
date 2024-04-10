#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> edge;

const ll inf = 1e9;

int main()
{

    //ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("mine.txt");

    ll n, m;
    cin >> n >> m;

    ll l = 0, r = inf;

    while (l != r - 1) {
        ll s = (l + r + 1) >> 1;
        ll s1 = s / 2, s2 = s / 3, s3 = s / 6;
        s1 -= s3, s2 -= s3;
        if (max(0ll, n - s1) + max(0ll, m - s2) > s3) {
            l = s;
        } else {
            r = s;
        }
    }

    cout << r << "\n";

}