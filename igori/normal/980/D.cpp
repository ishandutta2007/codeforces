#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string>
#include <set>
#include <bitset>
#include <map>

using namespace std;

int n, a[500000];
vector<int> vec;

const long long MOD = 1e9 + 7;
const int M = 7;

int ans[5001];
map<int, int> last;
int b[5001];

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vec.push_back(-1);
    for (int i = 2; i <= 10000; i++)
    {
        int t = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                t = 0;
                break;
            }
        }
        if (t)
        {
            vec.push_back(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0) continue;
        for (int j = 2; j <= 10000; j++)
        {
            while (a[i] % (j * j) == 0)
            {
                a[i] /= (j * j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        a[i] += 100000000;
        if (last[a[i]] == 0)
            last[a[i]] = i + 1;
        b[i] = last[a[i]];
    }
    for (int l = 0; l < n; l++)
    {
        vector<int> cnt(n + 1);
        int is_zero = 0, kek = 0;
        for (int r = l; r < n; r++)
        {
            cnt[b[r]]++;
            if (cnt[b[r]] == 1) kek++;
            if (a[r] == 100000000) is_zero = 1;
            ans[max(1, kek - is_zero)]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}