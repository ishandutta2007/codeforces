#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;

const int N = 1000 * 1000 + 100;

int main()
{

    bool p[N];
    for (int i = 2; i < N; i++)
        p[i] = true;

    for (int i = 2; i < N; i++)
    {
        if (p[i])
        for (int j = 2; i * j < N; j++)
            p[i * j] = false;
    }

    int n;
    cin >> n;

    for (int x = 4; x <= n; x++)
        if (!p[x] && !p[n - x]) {cout << x << " " << n - x << "\n"; return 0;}

}