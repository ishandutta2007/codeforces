#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
vector<int> pref;
vector<int> suff;

void updatepref(int pos, int val)
{
    for (; pos < n; pos = (pos | (pos + 1))) {
        pref[pos] += val;
    }
}

int getpref(int pos)
{
    int ans = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        ans += pref[pos];
    }
    return ans;
}

void updatesuff(int pos, int val)
{
    for (; pos < n; pos = (pos | (pos + 1))) {
        suff[pos] += val;
    }
}

int getsuff(int pos)
{
    int ans = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        ans += suff[pos];
    }
    return ans;
}

int main()
{

    //ios::sync_with_stdio(false);

    int k, a, b, q;
    scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
    pref.resize(n);
    suff.resize(n);

    vector<int> ma(n), mb(n);
    while (q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int day, cnt;
            scanf("%d%d", &day, &cnt);
            --day;
            int delta = min(cnt + mb[day], b) - mb[day];
            updatepref(day, delta);
            mb[day] = min(cnt + mb[day], b);
            delta = min(cnt + ma[day], a) - ma[day];
            updatesuff(n - 1 - day, delta);
            ma[day] = min(cnt + ma[day], a);
        } else {
            int day;
            scanf("%d", &day);
            --day;
            int ans = getpref(day - 1) + getsuff(n - 1 - day - k);
            printf("%d\n", ans);
        }
    }

}