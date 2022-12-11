#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector <int> vi;

int main()
{

    int n, k;
    cin >> n >> k;

    int h[200500], s[200500];
    s[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        s[i] = s[i - 1] + h[i];
    }

    int otv = 1000000000;
    int j;

    for (int l = 1; l + k - 1 <= n; l++)
    {
        int r = l + k - 1;
        if (otv > s[r] - s[l - 1])
        {
            otv = s[r] - s[l - 1];
            j = l;
        }
    }

    cout << j;

}