#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define F first
#define S second
#define pb push_back


using namespace std;


const int N = 2e5 + 10;


int get(int x, int k)
{
    int cnt = 0;
    while (x > 1)
    {
        x = max(x - k, 1);
        cnt++;
    }
    return cnt;

}

int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    int n, k;
    scanf("%d%d", &n, &k);
    int l1 = get(n, k);
    int l2 = get(n - 1, k);
    printf("%d\n", l1 + l2);
    for (int i = n; i > 1; --i) printf("%d %d\n", i, max(1, i - k));            


    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}