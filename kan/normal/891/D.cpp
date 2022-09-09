#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 500005;

vector<int> gr[maxn];
int ansdown[maxn][2];
int ansdownif[maxn][2][3][2][2];
int sz[maxn];
int cntbad[maxn], cntodd[maxn];
int n;
ll answer;
bool isok[maxn];

void calcdown(int cur, int pr)
{
    sz[cur] = 1;
    for (auto t : gr[cur]) if (t != pr)
    {
        calcdown(t, cur);
        sz[cur] += sz[t];
    }
    ansdown[cur][0] = 0;
    ansdown[cur][1] = 0;
    isok[cur] = true;
    cntodd[cur] = 0;
    cntbad[cur] = 0;
    for (auto t : gr[cur]) if (t != pr)
    {
        isok[cur] &= isok[t];
        cntbad[cur] += !isok[t];
        cntodd[cur] += sz[t] % 2;
    }
    isok[cur] &= cntodd[cur] <= 1;
    ansdown[cur][0] += (isok[cur] && cntodd[cur] + (n - sz[cur]) % 2 <= 1); // 0
    ansdown[cur][1] += (isok[cur] && cntodd[cur] + (n - sz[cur] + 1) % 2 + 1 <= 1); // 1
    for (auto t : gr[cur]) if (t != pr)
    {
        for (int kbad = 0; kbad <= 1; kbad++)
        {
            for (int kodd = 0; kodd <= 2; kodd++)
            {
                for (int oddabove = 0; oddabove <= 1; oddabove++)
                {
                    // try 0
                    if ((kbad == 0 || !isok[t]) && kodd + oddabove == 1) // t has the same parity
                    {
                        ansdownif[cur][kbad][kodd][oddabove][0] += ansdown[t][0];
                    }
                    // try 1
                    if ((kbad == 0 || !isok[t]) && kodd - sz[t] % 2 + (sz[t] + 1) % 2 + (oddabove + 1) % 2 == 1) // t has another parity
                    {
                        ansdownif[cur][kbad][kodd][oddabove][1] += ansdown[t][1];
                    }
                }
            }
        }
    }
    if (cntbad[cur] <= 1 && cntodd[cur] <= 2)
    {
        ansdown[cur][0] += ansdownif[cur][cntbad[cur]][cntodd[cur]][(n - sz[cur]) % 2][0];
        ansdown[cur][1] += ansdownif[cur][cntbad[cur]][cntodd[cur]][(n - sz[cur]) % 2][1];
    }
}

void calcup(int cur, int pr, int ansup0, int ansup1, bool isupok)
{
    if (pr != -1)
    {
        if (sz[cur] % 2 == 0)
        {
            answer += (ll)ansup0 * ansdown[cur][0];
        } else
        {
            answer += (ll)ansup1 * ansdown[cur][1];
        }
    }
    for (auto t : gr[cur]) if (t != pr)
    {
        int nowcntbad = cntbad[cur] + !isupok - !isok[t];
        int nowcntodd = cntodd[cur] + (n - sz[cur]) % 2 - sz[t] % 2;
        bool isnewok = isupok && (cntbad[cur] == 0 || (cntbad[cur] == 1 && !isok[t]));
        isnewok &= nowcntodd <= 1;
        if (nowcntbad > 1 || nowcntodd > 2) continue;
        int curansup0 = ansdownif[cur][nowcntbad][nowcntodd][sz[t] % 2][0];
        int curansup1 = ansdownif[cur][nowcntbad][nowcntodd][sz[t] % 2][1];

        if (isnewok && nowcntodd + sz[t] % 2 <= 1) curansup0++;
        if (isnewok && nowcntodd + 1 + (sz[t] + 1) % 2 <= 1) curansup1++;

        if ((nowcntbad == 0 || !isupok) && nowcntodd + sz[t] % 2 == 1) curansup0 += ansup0;
        if ((nowcntbad == 0 || !isupok) && nowcntodd - (n - sz[cur]) % 2 + (n - sz[cur] + 1) % 2 + (sz[t] + 1) % 2 == 1) curansup1 += ansup1;
        
        
        // try 0
        if ((nowcntbad == 0 || !isok[t]) && nowcntodd + sz[t] % 2 == 1) // t has the same parity
        {
            curansup0 -= ansdown[t][0];
        }
        // try 1
        if ((nowcntbad == 0 || !isok[t]) && nowcntodd - sz[t] % 2 + (sz[t] + 1) % 2 + (sz[t] + 1) % 2 == 1) // t has another parity
        {
            curansup1 -= ansdown[t][1];
        }
        
        calcup(t, cur, curansup0, curansup1, isnewok);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        gr[a].pb(b);
        gr[b].pb(a);
    }
    if (n % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    calcdown(0, -1);
    calcup(0, -1, 0, 0, 1);
    cout << answer << endl;
    return 0;
}