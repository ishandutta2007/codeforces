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
    while (n--)
    {
        int a;
        cin >> a;
        if (360 % (180 - a) == 0 && 360 / (180 - a) > 2) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }

}