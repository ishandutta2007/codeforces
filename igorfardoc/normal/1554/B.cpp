#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> pos(n + 1, {-INF, -INF});
        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            pos[a].second = pos[a].first;
            pos[a].first = i + 1;
        }
        ll res = (ll)-INF * INF;
        for(int mask = 0; mask < 2 * n; mask++)
        {
            int max1 = -INF;
            int max2 = -INF;
            for(int submask = mask; ; submask = (submask - 1) & mask)
            {
                //cout << submask << endl;
                if(submask > n)
                {
                    continue;
                }
                if(pos[submask].first > max1)
                {
                    max2 = max1;
                    max1 = pos[submask].first;
                }
                else if(pos[submask].first > max2)
                {
                    max2 = pos[submask].first;
                }
                if(pos[submask].second > max1)
                {
                    max2 = max1;
                    max1 = pos[submask].second;
                }
                else if(pos[submask].second > max2)
                {
                    max2 = pos[submask].second;
                }
                if(submask == 0)
                {
                    break;
                }
            }
            if(max1 != -INF && max2 != -INF)
            {
                res = max(res, (ll)max1 * max2 - (ll)k * mask);
            }
        }
        cout << res << '\n';
    }
}