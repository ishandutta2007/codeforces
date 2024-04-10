#include <iostream>
#include <cstdio>

using namespace std;

const int SIZE = (1 << 14), MAX_BITS = 14;

int a[SIZE], n, k, cur, b[SIZE], b_size = 0;

long long ans = 0;

void f(int lvl, int left, int cur_num)
{
    if (lvl == k)
    {
        b[b_size++] = cur_num;
        return;
    }
    int right = MAX_BITS - (k - lvl);
    for (int i = left; i <= right; ++i)
        f(lvl + 1, i + 1, (cur_num | (1 << i)));
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        ++a[x];
    }
    if (!k)
    {
        long long ans = 0;
        for (int i = 0; i < SIZE; ++i)
            ans += 1LL * a[i] * (a[i] - 1) / 2;
        cout << ans;
        return 0;
    }
    f(0, 0, 0);
    for (int i = 0; i < SIZE; i++)
        if (a[i])
            for (int j = 0; j < b_size; j++)
                ans += 1LL * a[i] * a[(i ^ b[j])];
    cout << ans / 2;
    return 0;
}