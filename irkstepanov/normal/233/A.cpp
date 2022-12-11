#include <bits/stdc++.h>

#define x first
#define y second

#define mp make_pair
#define pb push_back

using namespace std;

typedef pair <int, int> cell;

int main()
{

    int n;
    cin >> n;

    if (n % 2) {cout << "-1"; return 0;}

    for (int i = 1; i <= n; i += 2)
        cout << i + 1 << " " << i << " ";

}