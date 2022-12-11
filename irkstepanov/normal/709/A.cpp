#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, b, d;
    cin >> n >> b >> d;
    
    int ans = 0, curr = 0;
    
    while (n--) {
        int a;
        cin >> a;
        if (a > b) {
            continue;
        }
        curr += a;
        if (curr > d) {
            curr = 0;
            ++ans;
        }
    }
    cout << ans << "\n";

}