#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;

int main()
{

    //ifstream cin("input");
    //ofstream cout("output");

    int n, h;
    cin >> n >> h;

    int ans = 0;
    while (n--) {
        int a;
        cin >> a;
        if (a > h) {
            ans += 2;
        } else {
            ++ans;
        }
    }

    cout << ans << "\n";

}