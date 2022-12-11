#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

int main()
{

    ifstream cin("input.txt");
    ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    int pos;
    cin >> pos;

    vector<char> x(4, false);
    x[pos] = true;

    for (int i = 0; i < 3; ++i) {
        int u, v;
        cin >> u >> v;
        swap(x[u], x[v]);
    }

    for (int i = 1; i < 4; ++i) {
        if (x[i]) {
            cout << i << "\n";
        }
    }

}