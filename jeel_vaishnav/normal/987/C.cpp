#include <bits/stdc++.h>

using namespace std;

const int inf = INT_MAX;

class Display {
public:
    int size, cost;
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    int n;
    cin >> n;

    Display display[n];

    for(int i = 0; i < n; ++i)
        cin >> display[i].size;
    for(int i = 0; i < n; ++i)
        cin >> display[i].cost;

    int ans = inf;
    for(int i = 1; i < n - 1; ++i) {
        int ccost = display[i].cost;

        int mincost = inf;
        for(int j = 0; j < i; ++j) {
            if(display[j].size < display[i].size) {
                mincost = min(mincost, display[j].cost);
            }
        }

        if(mincost == inf)
            continue;
        ccost += mincost;

        mincost = inf;
        for(int j = i + 1; j < n; ++j) {
            if(display[j].size > display[i].size)
                mincost = min(mincost, display[j].cost);
        }

        if(mincost == inf)
            continue;
        ccost += mincost;

        ans = min(ans, ccost);
    }

    if(ans == inf)
        cout << "-1";
    else
        cout << ans;

    return 0;
}