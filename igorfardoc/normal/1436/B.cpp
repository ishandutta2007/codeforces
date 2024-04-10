#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<bool> pr(1000001, true);
    for(int i = 2; i <= 1000000; i++)
    {
        if(pr[i] && (long long)i * i <= 1000000)
        {
            for(int j = i * i; j <= 1000000; j += i)
            {
                pr[j] = false;
            }
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n == 1)
        {
            cout << "1\n";
            continue;
        }
        int ch = 2;
        for(; ch <= 100000; ch++)
        {
            if(!pr[ch] && pr[ch + n - 1])
            {
                break;
            }
        }
        vector<int> mass(n);
        for(int i = 0; i < n - 1; i++)
        {
            mass[i] = 1;
        }
        mass[n - 1] = ch;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << mass[(j + i) % n] << " ";
            }
            cout << "\n";
        }
    }
}