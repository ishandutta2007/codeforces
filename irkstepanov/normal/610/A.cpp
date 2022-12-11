#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef unsigned int uuint;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ll n;
    cin >> n;

    if (n % 2) {
        cout << "0\n";
        return 0;
    }

    n /= 2;
    if (n % 2 == 0) {
        cout << (n / 2 - 1) << "\n";
    } else {
        cout << n / 2 << "\n";
    }

}