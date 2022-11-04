#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

vector<int> to_vector(ull a)
{
    vector<int> ans;
    while(a)
    {
        ans.push_back(a % 10);
        a /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

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
        auto a = to_vector(n);
        int ans = 100;
        ull now = 1;
        for(int i = 1; i <= 64; i++)
        {
            auto b = to_vector(now);
            int here = 0;
            for(int j = 0; j < a.size(); j++)
            {
                if(here < b.size() && a[j] == b[here])
                {
                    ++here;
                }
            }
            ans = min(ans, (int)a.size() - here + ((int)b.size() - here));
            now *= 2;
        }
        cout << ans << '\n';
    }
}