#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define fi first
#define se second

const int maxn = 100005;

int ans[maxn][2][4][2];
int n;
char s[maxn];

int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    ans[0][0][0][s[0] == '0'] = 1;
    ans[0][1][1][s[0] == '1'] = 1;
    int answer = 1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int inv = 0; inv < 2; inv++)
        {
            for (int kinv = 0; kinv <= 2; kinv++)
            {
                for (int need = 0; need < 2; need++)
                {
                    for (int winv = 0; winv < 2; winv++)
                    {
                        int now1 = (s[i + 1] == '1') ^ winv;
                        int len = ans[i][inv][kinv][need] + (now1 == need);
                        int nowkinv = kinv;
                        if (inv != winv) nowkinv++;
                        if (nowkinv > 2) continue;
                        answer = max(answer, len);
                        ans[i + 1][winv][nowkinv][need ^ (need == now1)] = max(ans[i + 1][winv][nowkinv][need ^ (need == now1)], len);
                    }
                }
            }
        }
    }
    cout << answer << endl;
    return 0;
}