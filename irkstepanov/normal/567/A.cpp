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

int main()
{

    int n;
    scanf("%d", &n);

    std::vector <int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    for (int i = 0; i < n; i++)
    {
        if (!i)
        {
            printf("%d %d\n", v[i + 1] - v[i], v[n - 1] - v[i]);
            continue;
        }
        if (i == n - 1)
        {
            printf("%d %d\n", v[i] - v[i - 1], v[i] - v[0]);
            continue;
        }
        printf("%d %d\n", min(v[i + 1] - v[i], v[i] - v[i - 1]), max(v[n - 1] - v[i], v[i] - v[0]));
    }

}