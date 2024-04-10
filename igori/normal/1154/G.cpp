#include <iostream>
#include <vector>

using namespace std;

int cnt[11000000];
vector<int> reader[11000000];
int n;
long long ans = 1e18;
long long a[1500000];
long long f1, f2;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        reader[a[i]].push_back(i);
    }
    for (int g = 1; g <= 10000000; g++)
    {
        long long cnt0 = 0;
        vector<int> c;
        for (int j = 1; j * g <= 10000000; j++)
        {
            if (cnt0 + cnt[j * g] >= 2)
            {
                for (int k = 0; c.size() < 2; k++)
                    c.push_back(reader[j * g][k]);
                if (a[c[0]] * a[c[1]] / g <= ans)
                {
                    ans = a[c[0]] * a[c[1]] / g;
                    f1 = min(c[0], c[1]);
                    f2 = max(c[0], c[1]);
                }
                break;
            }
            else
            {
                cnt0 += cnt[j * g];
                for (int k = 0; k < cnt[j * g]; k++)
                    c.push_back(reader[j * g][k]);
            }
        }
    }
    cout << f1 + 1 << " " << f2 + 1;
}