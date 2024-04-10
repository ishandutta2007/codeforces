#include <bits/stdc++.h>

#define x first
#define y second

#define mp make_pair
#define pb push_back

using namespace std;

typedef pair <int, int> cell;

int n;
int ans = 0;

int f (int k)
{
    int r = n - k;
    for (int i = 1; i <= r - 1; i++)
    {
        ++ans;
        ans += k;
    }
    ++ans;
}

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
        f (i);

    cout << ans;

}