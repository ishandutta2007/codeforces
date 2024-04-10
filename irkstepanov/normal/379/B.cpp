#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdlib>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

using namespace std;

typedef long long ll;

int main()
{

    int n;
    cin >> n;

    int a[500];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            for (int j = 1; j <= a[i]; j++)
                cout << "PRL";
        else
            for (int j = 1; j <= a[i]; j++)
                cout << "PLR";
        if (i != n - 1) cout << "R";
    }

}