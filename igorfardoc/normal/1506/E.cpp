#include<bits/stdc++.h>
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
        int n;
        cin >> n;
        vector<int> q(n);
        for(int i = 0; i < n; i++)
        {
            cin >> q[i];
            --q[i];
        }
        vector<int> a(n);
        vector<int> b(n);
        vector<bool> used(n, false);
        int now = 0;
        int now1 = 0;
        vector<pair<int, int> > blocks;
        int prev = 0;
        for(int i = 1; i < n; i++)
        {
            if(q[i] != q[i - 1])
            {
                blocks.push_back({q[i - 1], i - prev});
                prev = i;
            }
        }
        blocks.push_back({q[n - 1], n - prev});
        for(int i = 0; i < blocks.size(); i++)
        {
            int ch = blocks[i].first;
            int am = blocks[i].second;
            a[now++] = ch;
            used[ch] = true;
            for(int j = 0; j < am - 1; j++)
            {
                while(used[now1])
                {
                    ++now1;
                }
                a[now++] = now1;
                used[now1] = true;
            }
        }
        for(int i = 0; i < n; i++)
        {
            cout << a[i] + 1 << ' ';
        }
        cout << '\n';
        now = 0;
        set<int> ok;
        for(int i = 0; i < n; i++)
        {
            ok.insert(-i);
        }
        for(int i = 0; i < blocks.size(); i++)
        {
            int ch = blocks[i].first;
            int am = blocks[i].second;
            b[now++] = ch;
            ok.erase(ok.find(-ch));
            for(int j = 0; j < am - 1; j++)
            {
                auto it = ok.lower_bound(-ch);
                b[now++] = -(*it);
                ok.erase(it);
            }
        }
        for(int i = 0; i < n; i++)
        {
            cout << b[i] + 1 << ' ';
        }
        cout << '\n';
    }
}