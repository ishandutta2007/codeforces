#include<bits/stdc++.h>
using namespace std;

vector<char> layer(vector<char> & mass, int now, int n, int k)
{
    vector<char> ret;
    for(int i = now; i < n && i < (now + k); i++)
    {
        ret.push_back(mass[i]);
    }
    return ret;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int o = 0; o < t; o++)
    {
        int n, k;
        cin >> n >> k;
        string str;
        vector<char> mass(n);
        cin >> str;
        for(int i = 0; i < n; i++)
        {
            mass[i] = str[i];
        }
        sort(mass.begin(), mass.end());
        vector<string> res(k);
        for(int i = 0; i < k; i++)
        {
            res[i] += mass[i];
        }
        if(res[0] != res[k - 1])
        {
            cout << res[k - 1] << endl;
            continue;
        }
        if(n == k)
        {
            cout << res[0] << endl;
            continue;
        }
        bool ok = true;
        for(int i = k + 1; i < n; i++)
        {
            if(mass[i] != mass[i - 1])
            {
                string result = res[0];
                for(int j = k; j < n; j++)
                {
                    result += mass[j];
                }
                cout << result << endl;
                ok = false;
                break;
            }
        }
        if(ok)
        {
            string result = res[0];
            for(int i = 0; i < (n - k - 1) / k + 1; i++)
            {
                result += mass[k];
            }
            cout << result << endl;
        }
    }
}