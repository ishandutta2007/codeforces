#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <queue>
#include <cstdlib>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

using namespace std;

const int inf = 1000000000;

typedef pair <int, int> pii;

int main()
{

    int n, m;
    cin >> n >> m;

    vector <int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    queue <int> q;
    for (int i = 0; i < n; i++)
        q.push(i);

    int last;
    while(!q.empty())
    {
        last = q.front();
        q.pop();
        a[last] -= m;
        if (a[last] > 0) q.push(last);
    }

    cout << last + 1;

}