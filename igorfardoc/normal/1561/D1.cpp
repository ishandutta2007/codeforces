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
    int now = 0;
    ans[n] = 1;
    for(int i = n; i >= 2; i--)
    {
        int here = (now + ans[i]) % m;
        now = (now + here) % m;
        int pred = i + 1;
        for(int j = 1; j * j < i; j++)
        {
            int next = i / (j + 1) + 1;
            ans[j] = (ans[j] + (ll)here * (pred - next)) % m;
            pred = next;
        }
        for(int j = pred - 1; j >= 2; j--)
        {
            ans[i / j] = (ans[i / j] + here) % m;
        }
    }
    cout << (now + ans[1]) % m;
}