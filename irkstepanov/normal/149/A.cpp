#include <bits/stdc++.h>

#define x first
#define y second

#define mp make_pair
#define pb push_back

using namespace std;

typedef pair <int, int> cell;

int main()
{

    int k;
    int a[15];

    cin >> k;
    for (int i = 0; i < 12; i++)
        cin >> a[i];

    sort (a, a + 12);
    int kol = 0;
    int otv = -1;

    if (kol >= k) otv = 0;

    else for (int i = 11; i >= 0; i--)
    {
        kol += a[i];
        if (kol >= k) {otv = 12 - i; break;}
    }

    cout << otv;

}