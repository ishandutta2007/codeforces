#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int maxn = 105;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int tt, m;
    cin >> tt >> m;

    int a[maxn];
    for (int i = 1; i <= m; i++)
        a[i] = -1;

    int ans = 1;

    while (tt--)
    {
        string s;
        cin >> s;
        if (s == "alloc")
        {
            int x;
            cin >> x;
            int l, cnt = 0;
            for (l = 1; l <= m; l++)
            {
                if (a[l] == -1) ++cnt;
                else cnt = 0;
                if (cnt == x) break;
            }
            if (cnt != x) {cout << "NULL\n"; continue;}
            for (cnt = 0; cnt < x; cnt++, --l)
                a[l] = ans;
            cout << ans << "\n";
            ++ans;
        }
        else if (s == "erase")
        {
            int x;
            cin >> x;
            if (x < 1) {cout << "ILLEGAL_ERASE_ARGUMENT\n"; continue;}
            bool ok = false;
            for (int l = 1; l <= m; l++)
                if (a[l] == x)
                {
                    a[l] = -1;
                    ok = true;
                }
            if (!ok) {cout << "ILLEGAL_ERASE_ARGUMENT\n";}
        }
        else if (s == "defragment")
        {
            int l, r;
            for (l = 1, r = 1; r <= m; r++)
                if (a[r] != -1) a[l++] = a[r];
            for (; l <= m; l++)
                a[l] = -1;
        }
    }

}