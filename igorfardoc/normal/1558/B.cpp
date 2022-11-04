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
    int n, m;
    cin >> n >> m;
    vector<int> ans(n + 1);
    ans[1] = 1;
    int now = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum = (sum + ans[i]) % m;
        if(i > 2)
        {
            sum = (sum + ans[i - 1]) % m;
        }
        ans[i] = sum;
        for(int j = 2; i * j <= n; j++)
        {
            ans[i * j] = ((ll)ans[i * j] + ans[i] - ans[i - 1] + m) % m;
        }
    }
    cout << ans[n];
}