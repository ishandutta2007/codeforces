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
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<int> pref1(n + 1), pref2(n + 1);
        for(int i = 1; i <= n; i++)
        {
            pref1[i] = pref1[i - 1];
            pref2[i] = pref2[i - 1];
            int here = 1;
            if(s[i - 1] == '-')
            {
                here = -1;
            }
            if(i % 2 == 1)
            {
                pref1[i] += here;
            }
            else
            {
                pref2[i] += here;
            }
        }
        for(int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            if((r - l + 1) % 2 == 1)
            {
                cout << "1\n";
                continue;
            }
            if(pref1[r + 1] - pref1[l] == pref2[r + 1] - pref2[l])
            {
                cout << "0\n";
            }
            else
            {
                cout << "2\n";
            }
        }
    }
}