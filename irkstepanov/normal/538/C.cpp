#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef unsigned long long ll;
typedef pair <int, int> pii;
typedef long double ld;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n, q;
    scanf("%d %d", &n, &q);

    int ans = 0;

    int prev_d = -1, prev_h = -1;

    while (q--)
    {
        int d, h;
        scanf("%d %d", &d, &h);
        if (prev_d == -1)
        {
            prev_d = d;
            prev_h = h;
            ans = d - 1 + h;
            continue;
        }
        if (prev_d != -1 && abs(h - prev_h) > d - prev_d) {printf("IMPOSSIBLE\n"); return 0;}
        if (abs(h - prev_h == d - prev_d))
        {
            prev_d = d;
            ans = max(ans, h);
            prev_h = h;
            continue;
        }
        int x = (d - prev_d + h + prev_h) / 2;
        ans = max(ans, x);
        prev_d = d;
        prev_h = h;
    }

    ans = max(ans, prev_h + n - prev_d);
    printf("%d\n", ans);

}