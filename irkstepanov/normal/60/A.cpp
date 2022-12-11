#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main()
{

    //memset(pro, -1, sizeof(pro));
 
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int lf = 1, rg = n;
    while (m--) {
        string s;
        cin >> s;
        cin >> s;
        cin >> s;
        string t = s;
        cin >> s;
        int val;
        cin >> val;
        if (t == "left") {
            rg = min(rg, val - 1);
        } else {
            lf = max(lf, val + 1);
        }
    }
    if (lf <= rg) {
        cout << rg - lf + 1 << "\n";
    } else {
        cout << "-1\n";
    }

}