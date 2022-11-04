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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> poses;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '*')
            {
                poses.push_back(i);
            }
        }
        if(poses.size() == 0)
        {
            cout << "0\n";
            continue;
        }
        int ans = 1;
        int prev = poses[0];
        for(int i = 1; i < poses.size(); i++)
        {
            if(prev + k < poses[i])
            {
                prev = poses[i - 1];
                ++ans;
            }
        }
        if(poses.size() > 1)
        {
            ++ans;
        }
        cout << ans << '\n';
    }
}