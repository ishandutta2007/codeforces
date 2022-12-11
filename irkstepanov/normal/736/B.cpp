#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

bool isPrime(ll x)
{
    for (ll i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{

    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;

    if (isPrime(n)) {
        cout << "1\n";
        return 0;
    }

    if (n % 2 == 0) {
        cout << "2\n";
        return 0;
    }

    if (isPrime(n - 2)) {
        cout << "2\n";
        return 0;
    }
    cout << "3\n";

}