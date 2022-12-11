#include <bits/stdc++.h>

#define x first
#define y second

#define mp make_pair
#define pb push_back

using namespace std;

typedef pair <int, int> cell;

int main()
{

    int chet = 0, nech = 0;
    int ch, ne;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x % 2) {++nech; ne = i;}
        else {++chet; ch = i;}
    }

    if (nech == 1) cout << ne;
    else cout << ch;

}