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

struct event
{
    char c;
    int a;
};

int main()
{

    int n;
    scanf("%d\n", &n);

    std::set <int> s;
    std::vector <event> v(n);
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%c %d\n", &v[i].c, &v[i].a);
        if (v[i].c == '-' && !s.count(v[i].a)) ++start;
        s.insert(v[i].a);
    }

    int ans = start, cur = start;
    for (int i = 0; i < n; i++)
    {
        if (v[i].c == '-')
        {
            --cur;
        }
        else
        {
            ++cur;
            ans = max(ans, cur);
        }
    }

    printf("%d\n", ans);

}