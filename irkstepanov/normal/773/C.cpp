#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#define int long long int

using namespace std;

main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin>>N;
    vector<long long> left;
    vector<vector<long long> > steps(60);
    for(int i = 0; i < N; ++i)
    {
        long long x;
        cin>>x;
        long long old = x;
        int k = 0;
        while (old > 1)
        {
            if (old % 2)
            {
                break;
            }
            old /= 2;
            k++;
        }
        if (old == 1)
        {
            steps[k].push_back(x);
        }
        else
        {
            left.push_back(x);
        }
    }
    vector<int> last(N);
    if (steps[0].size())
    {
        last[steps[0].size()-1] = 1;
    }
    for(int i = 1; i < 60; ++i)
    {
        while(steps[i].size() > steps[i-1].size())
        {
            left.push_back(steps[i].back());
            steps[i].pop_back();
        }
        if (steps[i].size())
        {
            last[steps[i].size()-1] = steps[i].back();
        }
    }
    for(int i = N-2; i >= 0; --i)
    {
        last[i] = max(last[i], last[i+1]);
    }
    int cntone = steps[0].size();
    int l = 0;
    int r = cntone + 1;
    while(r - l > 1)
    {
        int m = (r + l) / 2;
        vector<int> cur;
        for(auto el:left)
        {
            cur.push_back(el);
        }
        for(int i = 0; i < 60; ++i)
        {
            for(int y = m; y < steps[i].size(); ++y)
            {
                cur.push_back(steps[i][y]);
            }
        }
        sort(cur.rbegin(), cur.rend());
        int can = 1;
        for(int i = 0; i < cur.size(); ++ i)
        {
            if (cur[i] <= 2 * last[i])
            {
                continue;
            }
            can = 0;
            break;
        }
        if (cur.size() > m)
        {
            can = 0;
        }
        if (can)
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    //cout<<l<<' '<<r<<endl;
    if (cntone == 0 || l == cntone)
    {
        cout<<-1<<endl;
    }
    else
    {
        for(int i = l + 1; i <= cntone; ++i)
        {
            cout<<i<<' ';
        }
        cout<<endl;
    }
}