
#include <bits/stdc++.h>
 
using namespace std;
 
long long n, v[5000], d[5000], p[5000];
bool used[5000];
 
int main()
{
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        used[i] = true;
        cin >> v[i] >> d[i] >> p[i];
    }
    vector<long long> ans;
    for (long long i = 0; i < n; i++)
    {
        long long t = 0;
        while ((p[t] >= 0 || !used[t]) && t < n)
            t++;
        if (t == n)
        {
            t = 0;
            while (!used[t])
                t++;
            used[t] = false;
            if (t == n)
                break;
            ans.push_back(t + 1);
            long long k = 0;
            for (long long j = t + 1; j < n; j++)
                if (used[j] && k <= v[t])
                {
                    p[j] -= (v[t] - k);
                    k++;
                }
            continue;
        }
        used[t] = false;
        for (long long j = t + 1; j < n; j++)
            p[j] -= d[t];
    }
    cout << ans.size() << endl;
    for (long long i = 0; i < ans.size(); i++)
        if (p[ans[i] - 1] >= 0)
            cout << ans[i] << " ";
    return 0;
}