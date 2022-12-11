#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

void add(int& i, int n)
{
    ++i;
    if (i == n) {
        i = 0;
    }
}

int main()
{

    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int i;
    for (i = 0; a[i] != 1; ++i) ;
    int j;
    for (j = 0; b[j] != 1; ++j) ;

    int f = 0;
    while (f < n - 1) {
        if (a[i] == 0) {
            add(i, n);
            continue;
        }
        if (b[j] == 0) {
            add(j, n);
            continue;
        }
        if (a[i] == b[j]) {
            add(i, n);
            add(j, n);
            ++f;
            continue;
        }
        f = -1;
        break;
    }

    cout << (f == n - 1 ? "YES\n" : "NO\n");

}