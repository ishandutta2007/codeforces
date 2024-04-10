#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <time.h>

using namespace std;
#define td typedef
td long long ll;

#define pb push_back
#define fi first
#define se second
#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(x) x.begin(), x.end()
ll n, k;
ll a[1500000];
int go[21][1100000];
int agro[1500000];

int tree[4000100];
int push[4000100];

#define int long long

void upd(int V)
{
    tree[2 * V + 1] += push[V];
    push[2 * V + 1] += push[V];
    tree[2 * V + 2] += push[V];
    push[2 * V + 2] += push[V];
    push[V] = 0;
}

ll Set(int l, int v, int L, int R, int V)
{
    int r = l + 1;
    if (r <= L || R <= l)
        return 0;
    if (l <= L && R <= r)
    {
        tree[V] = v;
        //cout << V << " " << v << endl;
        return 0;
    }
    upd(V);
    int M = (L + R) / 2;
    Set(l, v, L, M, 2 * V + 1);
    Set(l, v, M, R, 2 * V + 2);
    tree[V] = max(tree[2 * V + 1], tree[2 * V + 2]);
}
ll get(int l, int r, int L, int R, int V)
{
    //cout << l << " " << r << " " << L << " " << R << endl;
    if (r <= L || R <= l)
        return 0;
    if (l <= L && R <= r)
    {
        return tree[V];
    }
    upd(V);
    int M = (L + R) / 2;
    return max(get(l, r, L, M, 2 * V + 1), get(l, r, M, R, 2 * V + 2));
}
ll er(int l, int r, int L, int R, int V)
{
    if (r <= L || R <= l)
        return 0;
    if (l <= L && R <= r)
    {
        tree[V]--;
        push[V]--;
        return 0;
    }
    upd(V);
    int M = (L + R) / 2;
    er(l, r, L, M, 2 * V + 1);
    er(l, r, M, R, 2 * V + 2);
    tree[V] = max(tree[2 * V + 1], tree[2 * V + 2]);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    a[n] = n + 1;
    vector<pair<int, int> > st;
    st.push_back({n + 1, n});
    go[0][n] = n;
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() > 0 && a[i] >= st[st.size() - 1].first)
            st.pop_back();
        go[0][i] = st[st.size() - 1].second; 
        st.push_back({a[i], i});
    }
    st.resize(0);
    st.push_back({n + 1, -1});
    for (int i = 0; i < n; i++)
    {
        while (st.size() > 0 && a[i] > st[st.size() - 1].first)
            st.pop_back();
        agro[i] = st[st.size() - 1].second; 
        st.push_back({a[i], i});
    }
    for (int j = 1; j <= 20; j++)
    {
        for (int i = 0; i <= n; i++)
        {
            long long a1 = go[j - 1][i];
            long long a2 = go[j - 1][a1];
            go[j][i] = a2;
            //cout << go[j][i] << " ";
        }
        //cout << endl;
    }
    vector<int> res;
    for (int i = 0; i <= n; i++)
    {
        int l = i, r = min(i + k - 1, n - 1), ans = 1;
        for (int j = 20; j >= 0; j--)
        {
            if (go[j][l] <= r)
            {
                l = go[j][l];
                ans += (1 << j);
            }
        }
        //cout << ans << " ";
        res.push_back(ans);
    }
    vector<int> answer;
    for (int i = n - 1; i > n - k; i--)
    {
        Set(i, res[i], 0, n, 0);
    }
    for (int i = n - k; i >= 0; i--)
    {
        Set(i, res[i], 0, n, 0);
        //cout << "OkSet" << endl;;
        answer.push_back(get(i, i + k, 0, n, 0));
        //cout << "OkGet" << endl;
        er(agro[i + k - 1], i + k, 0, n, 0);
        //cout << "OkEr" << endl;
    }
    while (answer.size())
    {
        cout << answer[answer.size() - 1] << " ";
        answer.pop_back();
    }
}