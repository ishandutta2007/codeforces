#include <bits/stdc++.h>

#define x first
#define y second

#define mp make_pair
#define pb push_back

using namespace std;

typedef pair <int, int> cell;

int main()
{

    int maxim, minim;
    int n;
    int ans = 0;

    cin >> n;
    int x;
    cin >> x;

    maxim = minim = x;
    n--;

    while (n--)
    {
        cin >> x;
        if (x > maxim) {maxim = x; ++ans;}
        if (x < minim) {minim = x; ++ans;}
    }

    cout << ans;

}