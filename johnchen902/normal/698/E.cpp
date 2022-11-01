#include <cstdio>
using namespace std;
 int dayofyear(int y) {
    y += 1970;
    return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)
            ? 366 : 365;
}
int sdoy[401];
int sumdayofyear(int y) {
    return (y / 400) * sdoy[400] + sdoy[y % 400];
}
int getyear(int d) {
    int y = 1;
    while(sumdayofyear(y) <= d)
        y <<= 1;
    int ans = 0;
    for(int j = y; j >= 1; j >>= 1)
        if(sumdayofyear(ans + j) <= d)
            ans += j;
    return ans;
}
 int getday(long long t) {
    return (t / 86400 + 3) % 7;
}
 int dom[12] =
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 int domy(int m, int y) {
    if(m == 1) {
        y += 1970;
        return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)
                ? dom[m] + 1 : dom[m];
    } else
        return dom[m];
}
int getdate(long long t) {
    int d = t / 86400;
    int y = getyear(d);
    d -= sumdayofyear(y);
    for(int i = 0; i < 12; i++) {
        if(d < domy(i, y))
            return d;
        d -= domy(i, y);
    }
    __builtin_unreachable();
}
int getmonth(long long t) {
    int d = t / 86400;
    int y = getyear(d);
    d -= sumdayofyear(y);
    for(int i = 0; i < 12; i++) {
        if(d < domy(i, y))
            return i;
        d -= domy(i, y);
    }
    __builtin_unreachable();
}
long long solve(long long t, int s, int m, int h,
        int day, int date, int month) {
    if(s != -1)
        while(t % 60 != s)
            t++;
    if(m != -1)
        while(t / 60 % 60 != m) {
            t += 60;
            if(s == -1)
                t -= t % 60;
        }
    if(h != -1)
        while(t / 3600 % 24 != h) {
            t += 3600;
            if(m == -1)
                t -= t / 60 % 60 * 60;
            if(s == -1)
                t -= t % 60;
        }
    while((month != -2 && getmonth(t) != month) ||
            (day != -2 && date != -2 && getday(t) != day && getdate(t) != date) ||
            (day != -2 && date == -2 && getday(t) != day) ||
            (day == -2 && date != -2 && getdate(t) != date)) {
        if(month != -2 && getmonth(t) != month) {
            t += (domy(getmonth(t), getyear(t / 86400)) - getdate(t)) * 86400;
        } else {
            t += 86400;
        }
        if(h == -1)
            t -= t / 3600 % 24 * 3600;
        if(m == -1)
            t -= t / 60 % 60 * 60;
        if(s == -1)
            t -= t % 60;
    }
    return t;
}
int main() {
    for(int i = 0; i < 400; i++)
        sdoy[i + 1] = sdoy[i] + dayofyear(i);

    int s, m, h, day, date, month;
    scanf("%d%d%d%d%d%d", &s, &m, &h, &day, &date, &month);
    int n;
    scanf("%d", &n);
    while(n--) {
        long long t;
        scanf("%lld", &t);
        printf("%lld\n", solve(t + 1, s, m, h, day - 1,
                    date - 1, month - 1));
    }
}