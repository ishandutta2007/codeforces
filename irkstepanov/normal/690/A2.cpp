#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

bool power_of_2(int n)
{
    while (n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}

int max_deg(int n)
{
    for (int x = 1; ; ++x) {
        if ((1 << x) > n) {
            return x - 1;
        }
    }
}

int main()
{

    //freopen("input.txt", "r", stdin);

    //ifstream cin("input.txt");

    int n;
    cin >> n;

    if (power_of_2(n)) {
        cout << "0\n";
        return 0;
    }

    if (n % 2 == 0) {
        int x = max_deg(n);
        int y = (1 << x);
        cout << (n - y) / 2 << "\n";
    } else {
        cout << n / 2 << "\n";
    }

}