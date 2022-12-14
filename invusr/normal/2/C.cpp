#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef double r32;

const int N = 3;
const r32 eps = 1e-6;

struct circle
{
    r32 x, y;
    r32 radius;

    circle() {}
    circle(const r32 &_x, const r32 &_y, const r32 &_r)
        : x(_x), y(_y), radius(_r) {}
};
circle cir[N];

inline r32 sqr(const r32 &x)
{
    return x * x;
}

inline r32 get(const r32 &x, const r32 &y)
{
    r32 w1 = sqrt(sqr(x - cir[0].x) + sqr(y - cir[0].y)) / cir[0].radius;
    r32 w2 = sqrt(sqr(x - cir[1].x) + sqr(y - cir[1].y)) / cir[1].radius;
    r32 w3 = sqrt(sqr(x - cir[2].x) + sqr(y - cir[2].y)) / cir[2].radius;
    return sqr(w1 - w2) + sqr(w2 - w3) + sqr(w3 - w1);
}

int main()
{
    for (int i = 0; i < N; ++i)
    {
        scanf("%lf%lf", &cir[i].x, &cir[i].y);
        scanf("%lf", &cir[i].radius);
    }

    r32 curx = (cir[0].x + cir[1].x + cir[2].x) / 3.0;
    r32 cury = (cir[0].y + cir[1].y + cir[2].y) / 3.0;
    r32 curw = get(curx, cury);
    for (r32 s = 1.0, w; s > eps; 233)
    {
        bool ok = false;
        if (curw > (w = get(curx + s, cury)))
            curx += s, curw = w, ok = true;
        else if (curw > (w = get(curx - s, cury)))
            curx -= s, curw = w, ok = true;
        else if (curw > (w = get(curx, cury + s)))
            cury += s, curw = w, ok = true;
        else if (curw > (w = get(curx, cury - s)))
            cury -= s, curw = w, ok = true;
        if (!ok)
            s *= 0.7;
    }

    if (get(curx, cury) < 1e-5)
        printf("%.5f %.5f\n", curx, cury);

    return 0;
}