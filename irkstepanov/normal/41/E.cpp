#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main()
{

    //ifstream cin("input.txt");

    int n;
    cin >> n;

    int a = n / 2;
    int b = n - a;

    cout << a * b << "\n";
    for (int i = 1; i <= a; ++i) {
        for (int j = a + 1; j <= n; ++j) {
            cout << i << " " << j << "\n";
        }
    }

}