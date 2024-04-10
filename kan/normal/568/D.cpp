#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define pb push_back
#define all(x) begin(x), end(x)

const int MAXIT[6] = {0, 1, 6, 13, 20, 25};

struct line
{
    int a, b, c;
    int id;
};

vector<line> l;
int n, k;
vector<pair<int, int>> answer;

void solve(vector<line> &l, int k)
{
    int n = l.size();
    if (k >= (int)n)
    {
        for (int i = 0; i < (int)n; i++) answer.pb({l[i].id, -2});
        printf("YES\n");
        printf("%d\n", answer.size());
        for (auto t : answer) printf("%d %d\n", t.first + 1, t.second + 1);
        exit(0);
    }
    if (k == 0) return;
    for (int IT = 0; IT < MAXIT[k]; IT++)
    {
        int wh1 = rand() % n;
        int wh2 = rand() % (n - 1);
        if (wh2 >= wh1) wh2++;
        auto &l1 = l[wh1];
        auto &l2 = l[wh2];
        if ((ll)l1.a * l2.b == (ll)l2.a * l1.b) continue;
        vector<line> next;
        for (auto &t : l) if ((ll)l1.a * l2.b * t.c + (ll)l1.b * l2.c * t.a + (ll)l1.c * l2.a * t.b !=
                             (ll)l1.c * l2.b * t.a + (ll)l1.b * l2.a * t.c + (ll)l1.a * l2.c * t.b) next.pb(t);
        if ((int)next.size() > max((double)k - 1, n * (1.0 - 1.0 / (2 * k)))) continue;
        answer.pb({l1.id, l2.id});
        solve(next, k - 1);
        answer.pop_back();
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    l.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &l[i].a, &l[i].b, &l[i].c);
        l[i].id = i;
    }
    solve(l, k);
    printf("NO\n");
    return 0;
}