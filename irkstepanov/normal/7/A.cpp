#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int n = 8;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    char m[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        cin >> m[i][j];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (m[i][j] == 'B') ++cnt;
        if (cnt == n) ++ans;
    }

    if (ans == n) {cout << ans << "\n"; return 0;}

    for (int j = 0; j < n; j++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (m[i][j] == 'B') ++cnt;
        if (cnt == n) ++ans;
    }

    cout << ans << "\n";

}