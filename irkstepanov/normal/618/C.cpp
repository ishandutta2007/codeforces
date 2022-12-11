#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int nmax = 100500;

struct pt
{
    ll x, y;
};

ll dist(const pt& a, const pt& b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

struct line
{
    ll a, b, c;
};

line buildLine(const pt& p, const pt& q)
{
    line l;
    l.a = p.y - q.y;
    l.b = q.x - p.x;
    l.c = p.x * q.y - p.y * q.x;
    return l;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    scanf("%d", &n);

    vector<pt> p(n);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d%I64d", &p[i].x, &p[i].y);
    }

    int a = 1;
    for (int i = 2; i < n; ++i) {
        if (dist(p[0], p[i]) < dist(p[0], p[a])) {
            a = i;
        }
    }

    int b = -1;
    line l = buildLine(p[0], p[a]);

    for (int i = 1; i < n; ++i) {
        if (l.a * p[i].x + l.b * p[i].y + l.c == 0) {
            continue;
        }
        ll d = abs(l.a * p[i].x + l.b * p[i].y + l.c);
        if (b == -1 || d < abs(l.a * p[b].x + l.b * p[b].y + l.c)) {
            b = i;
        }
    }

    printf("%d %d %d\n", 1, a + 1, b + 1);

}