#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main()
{

    //ifstream cin("input.txt");

    int n;
    cin >> n;

    int ans = 2 * (n / 3);
    if (n % 3) {
        ++ans;
    }

    cout << ans << "\n";

}