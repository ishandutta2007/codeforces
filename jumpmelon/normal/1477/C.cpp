#include <bits/stdc++.h>
//resub
using namespace std;

typedef long long big;

const int MAXN = 5000;
int P[MAXN + 1];
struct vec2
{
    int x, y;
} A[MAXN + 1];

inline big dot(const vec2 &a, const vec2 &b) { return (big)a.x * b.x + (big)a.y * b.y; }
inline vec2 operator -(const vec2 &a, const vec2 &b) { return {a.x - b.x, a.y - b.y}; }

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &A[i].x, &A[i].y);
    for (int i = 1; i <= n; i++)
        P[i] = i;
    for (int tim = 1; tim <= 5000; tim++)
    {
        random_shuffle(P + 1, P + n + 1);
        for (int i = 2; i < n; i++)
            if (dot(A[P[i - 1]] - A[P[i]], A[P[i + 1]] - A[P[i]]) <= 0)
                swap(P[i], P[i + 1]);
        for (int i = 2; i < n; i++)
            if (dot(A[P[i - 1]] - A[P[i]], A[P[i + 1]] - A[P[i]]) <= 0)
                swap(P[i], P[i + 1]);
        bool fl = 1;
        for (int i = 2; i < n; i++)
            if (dot(A[P[i - 1]] - A[P[i]], A[P[i + 1]] - A[P[i]]) <= 0)
            {
                fl = 0;
                break;
            }
        if (fl)
        {
            for (int i = 1; i <= n; i++)
                printf("%d%c", P[i], i < n ? ' ' : '\n');
            return 0;
        }
    }
    puts("-1");
    return 0;
}