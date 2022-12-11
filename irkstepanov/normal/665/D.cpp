#include <iostream>
#include <map>
#include <vector>
#include <fstream>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int inf = 2e6 + 10;

vector<char> p(inf, true);

void init()
{
    for (int i = 2; i < inf; ++i) {
        if (!p[i]) {
            continue;
        }
        for (int j = 2 * i; j < inf; j += i) {
            p[j] = false;
        }
    }
}

int main()
{

    //ifstream cin("input.txt");

    init();

    int n;
    cin >> n;
    vector<int> odd, even;
    int cnt1 = 0;
    int ans = 1;
    vector<int> v;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v = {a};
        if (a == 1) {
            ++cnt1;
        } else if (a & 1) {
            odd.pb(a);
        } else {
            even.pb(a);
        }
    }

    for (int x : odd) {
        for (int y : even) {
            if (p[x + y]) {
                ans = 2;
                v = {x, y};
            }
        }
    }

    if (ans < cnt1) {
        ans = cnt1;
        v = {};
        for (int i = 0; i < cnt1; ++i) {
            v.pb(1);
        }
    }

    for (int y : even) {
        if (p[y + 1] && cnt1 + 1 > ans) {
            ans = cnt1 + 1;
            v = {y};
            for (int i = 0; i < cnt1; ++i) {
                v.pb(1);
            }
        }
    }

    cout << ans << "\n";
    for (int x : v) {
        cout << x << " ";
    }
    cout << "\n";

}