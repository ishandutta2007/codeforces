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
        vector<int> a(n);
        vector<int> cnt(101);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }
        for(int i = 0; i <= 100; i++)
        {
            if(cnt[i] != 0)
            {
                cout << n - cnt[i] << '\n';
                break;
            }
        }
    }
}