#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin >> n;

    vector <char> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int len = 1; len < n; len++)
        for (int i = 0; i < n; i++)
    {
        bool ok = true;
        for (int j = i; j <= i + 4 * len; j += len)
            if (j >= n || v[j] != '*') ok = false;
        if (ok) {cout << "yes\n"; return 0;}
    }

    cout << "no\n";

}