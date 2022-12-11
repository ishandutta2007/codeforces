#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

int main()
{

    //ifstream cin("input.txt");

    //freopen("input.txt", "r", stdin);

    int n, k;
    cin >> n >> k;

    int sum = 0;
    
    for (int i = 1; i <= n; ++i) {
        sum += 5 * i;
        if (sum + k > 240) {
            cout << i - 1 << '\n';
            return 0;
        }
    }

    cout << n << "\n";

}