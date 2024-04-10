#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 4005;

vector<int> ss, tt;
char s[maxn], t[maxn];
int n;
vector<int> answer;
int cnt[5];

vector<int> prepare(char *s)
{
    vector<int> ans;
    for (int i = 0; i < 2 * n; i += 2) ans.pb((s[i] - '0') * 2 + (s[i + 1] - '0'));
    return ans;
}

inline void addanswer(int x)
{
    if (x <= 0) return;
    answer.pb(x);
}

void doreverse(vector<int> &v, int l)
{
    reverse(v.begin(), v.begin() + l);
    for (int j = 0; j < l; j++) if (v[j] >= 1 && v[j] <= 2)
    {
        v[j] = 3 - v[j];
    }
}

int main()
{
    int NT;
    scanf("%d", &NT);
    for (int T = 0; T < NT; T++)
    {
        scanf("%s%s", s, t);
        n = strlen(s) / 2;
        ss = prepare(s);
        tt = prepare(t);
        for (auto &t : tt) if (t == 1 || t == 2) t = 3 - t;
        cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
        for (auto t : ss) cnt[t]++;
        for (auto t : tt) cnt[t]--;
        if (cnt[0] != 0 || cnt[3] != 0)
        {
            printf("-1\n");
            continue;
        }
        bool found = cnt[1] == 0;
        int before = -1;
        int after = -1;
        for (int i = 1; i <= n && !found; i++)
        {
            cnt[ss[i - 1]]--;
            cnt[3 - ss[i - 1]]++;
            if (cnt[1] == 0)
            {
                before = 2 * i;
                doreverse(ss, i);
                found = true;
            }
        }
        if (!found)
        {
            for (int i = 1; i <= n; i++)
            {
                cnt[ss[i - 1]]++;
                cnt[3 - ss[i - 1]]--;
            }
        }
        for (int i = 1; i <= n && !found; i++)
        {
            cnt[tt[i - 1]]++;
            cnt[3 - tt[i - 1]]--;
            if (cnt[1] == 0)
            {
                after = 2 * i;
                doreverse(tt, i);
                found = true;
            }
        }
        assert(found);
        
        answer.clear();
        addanswer(before);
        for (int i = n - 1; i >= 0; i--)
        {
            int wh = -1;
            for (int j = n - 1 - i; j < n; j++) if (ss[j] == tt[i]) wh = j;
            addanswer(2 * wh);
            doreverse(ss, wh);
            addanswer(2 * wh + 2);
            doreverse(ss, wh + 1);
        }
        addanswer(after);
        
        for (auto t : answer) reverse(s, s + t);
        assert(strcmp(s, t) == 0);
        
        printf("%d ", (int)answer.size());
        for (auto t : answer) printf("%d ", t);
        printf("\n");
    }
    return 0;
}