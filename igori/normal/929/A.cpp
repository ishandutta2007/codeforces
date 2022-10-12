#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz size()

using namespace std;

int main()
{
    int n, k;
    vector < int > v;
    cin >> n >> k;
    v.resize(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    int r = 0, cur = 0;
    for(int i = 0; i < n - 1; i++)
    {
        if(cur < v[i + 1] - v[i])
        {
            if(k < v[i + 1] - v[i])
            {
                cout << -1;
                return 0;
            }
            r++;
            cur = k;
        }
        cur -= v[i + 1] - v[i];
    }
    cout << r;
}