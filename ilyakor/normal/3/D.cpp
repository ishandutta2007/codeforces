#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <queue>
//#include <cmath>

#define mp make_pair
#define sz(v)((int)((v).size()))
#define all(v) v.begin(),v.end()
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x);}
template<class T> T sqr(T x) {return x * x;}

int a[100000][2];

void save()
{
    printf("-1\n");
    exit(0);
}

const int n = 65536;

int tree[57000 * 4 + 10];
int delta[57000 * 4 + 10];

void Set(int pos, int newval, int i = 1, int l = 0, int r = n - 1)
{
    if (l == r)
    {
        tree[i] = newval;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m)
        Set(pos, newval, i * 2, l, m);
    else
        Set(pos, newval, i * 2 + 1, m + 1, r);
    tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}

void multiinc(int l0, int r0, int val, int i = 1, int l = 0, int r = n - 1)
{
    if (l >= l0 && r <= r0)
    {
        delta[i] += val;
        return;
    }
    if (min(r, r0) < max(l, l0)) return;
    int m = (l + r) / 2;
    multiinc(l0, r0, val, 2 * i, l, m);
    multiinc(l0, r0, val, 2 * i + 1, m + 1, r);
    tree[i] = min(tree[2 * i] + delta[2 * i], tree[2 * i + 1] + delta[2 * i + 1]);
}

int get(int l0, int r0, int i = 1, int l = 0, int r = n - 1)
{
    if (min(r, r0) < max(l, l0))
        return 100000000;
    if (l >= l0 && r <= r0)
        return tree[i] + delta[i];
    int m = (l + r) / 2;
    return delta[i] + min(get(l0, r0, 2 * i, l, m), get(l0, r0, 2 * i + 1, m + 1, r));
}

int main()
{
    memset(tree, 0, sizeof(tree));
    string s;
    cin >> s;
    for (int i = 0; i < sz(s); i++)
    {
        if (s[i] != '?') continue;
        scanf("%d%d", &a[i][0], &a[i][1]);
    }
    set<ii> up, down;
    int cur = 0;
    int64 cost = 0;
    for (int i = 0; i < sz(s); i++)
    {
        if (s[i] == '?')
        {
            if (a[i][0] < a[i][1])
            {
                s[i] = '(';
                cost += a[i][0];
                down.insert(ii(a[i][1] - a[i][0], i));
                cur++;
            }
            else
            {
                s[i] = ')';
                cost += a[i][1];
                up.insert(ii(a[i][0] - a[i][1], i));
                cur--;
            }
        }
        else
        {
            cur += s[i] == '(' ? 1 : -1;
        }
        if (cur < 0)
        {
            if (up.empty()) save();
            set<ii>::iterator it = up.begin();
            cost += it->first;
            s[it->second] = '(';
            cur += 2;
            up.erase(it);
            down.clear();
        }
    }
    int ss = 0;
    for (int i = 0; i < sz(s); i++)
    {
        ss += s[i] == '(' ? 1 : -1;
        Set(i + 1, ss);
    }
    while (cur > 0)
    {
        if (down.empty()) save();
        set<ii>::iterator it = down.begin();
        int delt = it->first;
        int ind = it->second;
        down.erase(it);
        multiinc(ind + 1, sz(s), -2);
        int opt = get(1, sz(s));
        if (opt < 0)
        {
            multiinc(ind + 1, sz(s), 2);
            continue;
        }
        cur -= 2;
        s[ind] = ')';
        cost += delt;
    }
    cout << cost << "\n" << s << "\n";
    return 0;
}