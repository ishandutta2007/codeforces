#include<bits/stdc++.h>
using namespace std;
vector<int> a(6);
vector<int> b;
int n;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < 6; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cin >> n;
    b.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    vector<vector<int> > mass;
    for(int i = 0; i < n; i++)
    {
        if(i == 0 || b[i] != b[i - 1])
        {
            vector<int> mass1(6);
            for(int j = 0; j < 6; j++)
            {
                mass1[j] = b[i] - a[6 - j - 1];
            }
            mass.push_back(mass1);
        }
    }
    n = mass.size();
    if(n == 1)
    {
        cout << 0;
        return 0;
    }
    long long ans = 1000000000000ll;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            long long lmax = min(mass[0][i], mass[n - 1][j]);
            long long rmin = max(mass[0][i], mass[n - 1][j]);
            vector<pair<int, int> > pairs;
            for(int k = 1; k < n - 1; k++)
            {
                bool flag = true;
                int l1 = 0;
                int r1 = -1;
                for(int l = 0; l < 6; l++)
                {
                    if(mass[k][l] < lmax)
                    {
                        l1 = mass[k][l];
                    }
                    if(mass[k][l] > rmin && r1 == -1)
                    {
                        r1 = mass[k][l];
                    }
                    if(mass[k][l] >= lmax && mass[k][l] <= rmin)
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                {
                    pairs.push_back({l1, r1});
                }
            }
            sort(pairs.begin(), pairs.end());
            if(pairs.size() == 0)
            {
                ans = min(ans, rmin - lmax);
            }
            long long nowmax = rmin;
            for(int k = 0; k < pairs.size(); k++)
            {
                if(k == 0 || pairs[k].first != pairs[k - 1].first)
                {
                    ans = min(ans, nowmax - pairs[k].first);
                }
                nowmax = max(nowmax, (long long)pairs[k].second);
            }
        }
    }
    cout << ans;
}