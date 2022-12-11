#include <bits/stdc++.h>

#define mp std::make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

int max(int a, int b)
{
    return (a > b ? a : b);
}

int min(int a, int b)
{
    return (a < b ? a : b);
}

typedef long long ll;

const int nmax = 200500;
int l[2 * nmax], r[2 * nmax], n;

int get_l(int pos)
{
    int ans = l[pos + n];
    pos += n;
    for (pos >>= 1; pos; pos >>= 1)
    {
        ans = max(ans, l[pos]);
    }
    return ans;
}

int get_r(int pos)
{
    int ans = r[pos + n];
    pos += n;
    for (pos >>= 1; pos; pos >>= 1)
    {
        ans = min(ans, r[pos]);
    }
    return ans;
}

void update_r(int a, int b, int val)
{
    for (a += n, b += n; a <= b; a = (a + 1) >> 1, b = (b - 1) >> 1)
    {
        if (a & 1) r[a] = val;
        if (!(b & 1)) r[b] = val;
    }
}

void update_l(int a, int b, int val)
{
    for (a += n, b += n; a <= b; a = (a + 1) >> 1, b = (b - 1) >> 1)
    {
        if (a & 1) l[a] = val;
        if (!(b & 1)) l[b] = val;
    }
}

int main()
{

    int k, a;
    scanf("%d%d%d", &n, &k, &a);

    for (int i = 0; i < 2 * nmax; i++)
    {
        l[i] = 0;
        r[i] = n - 1;
    }

    int q;
    scanf("%d", &q);

    int ships = (n + 1) / (a + 1);

    for (int i = 1; i <= q; i++)
    {
        int x;
        scanf("%d", &x);
        --x;
        int left = get_l(x), right = get_r(x);
        //printf("%d %d\n", left, right);
        ships -= (right - left + 2) / (a + 1);
        ships += (x - left + 1) / (a + 1);
        ships += (right - x + 1) / (a + 1);
        if (ships < k)
        {
            printf("%d\n", i);
            return 0;
        }
        update_l(x + 1, right, x + 1);
        update_r(left, x - 1, x - 1);
//printf("%d\n", l[3]);
    }

    printf("-1\n");

}