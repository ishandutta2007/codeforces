#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void swap(vector<int>& a, int n)
{
    for(int i = 0; i < n / 2; i++)
    {
        int k = a[i];
        a[i] = a[n - i];
        a[n - i] = k;
    }
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
        vector<int> a(n);
        bool ok = true;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(i % 2 == a[i] % 2)
            {
                ok = false;
            }
        }
        if(!ok)
        {
            cout << "-1\n";
            continue;
        }
        vector<int> ans;
        for(int i = n - 1; i > 0; i -= 2)
        {
            int pos = -1;
            for(int j = 0; j <= i; j++)
            {
                if(a[j] == i + 1)
                {
                    pos = j;
                    break;
                }
            }
            if(pos != 0)
            {
                swap(a, pos);
                ans.push_back(pos);
            }
            for(int j = 0; j <= i; j++)
            {
                if(a[j] == i)
                {
                    pos = j;
                    break;
                }
            }
            if(pos - 1 != 0)
            {
                swap(a, pos - 1);
                ans.push_back(pos - 1);
            }
            swap(a, pos + 1);
            ans.push_back(pos + 1);
            swap(a, 2);
            ans.push_back(2);
            swap(a, i);
            ans.push_back(i);
        }
        if(!ok)
        {
            cout << "-1\n";
            continue;
        }
        cout << ans.size() <<'\n';
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] + 1 << ' ';
        }
        cout << '\n';
    }
}