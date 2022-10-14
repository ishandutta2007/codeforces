#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double boris2(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y)
{
    return dist(x1, y1, x, y)+dist(x2, y2, x, y)+dist(x3, y3, x, y);
}

double ts4(double x1, double y1, double x2, double y2, double x3, double y3, double m)
{
    double l = -2e4;
    double r = 2e4;
    double ans;
    while (r-l > 1e-6)
    {
        double m1 = (2*l+r)/3;
        double h1 = boris2(x1, y1, x2, y2, x3, y3, m, m1);
        double m2 = (l+2*r)/3;
        double h2 = boris2(x1, y1, x2, y2, x3, y3, m, m2);
        ans = (h1+h2)/2;
        if (h1 > h2)
            l = m1;
        else
            r = m2;
    }
    return ans;
}

double ts3(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double a = dist(x1, y1, x2, y2);
    double b = dist(x1, y1, x3, y3);
    double c = dist(x3, y3, x2, y2);

    double mn = min({a, b, c});
    double mx = max({a, b, c});
    double sr = a+b+c-mn-mx;
    if (abs(mn) > 1e-4)
    if ( (mn*mn + sr*sr - mx*mx) / 2 / sr / mn < -0.5) /// tupoy
    {
        return mn+sr;
    }

    double l = -2e4;
    double r = 2e4;
    double ans;
    while (r-l > 1e-6)
    {
        double m1 = (2*l+r)/3;
        double h1 = ts4(x1, y1, x2, y2, x3, y3, m1);
        double m2 = (l+2*r)/3;
        double h2 = ts4(x1, y1, x2, y2, x3, y3, m2);
        ans = (h1+h2)/2;
        if (h1 > h2)
            l = m1;
        else
            r = m2;
    }
    return ans;
}

double boris(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y)
{
    double res =  max({ ts3(x1, y1, x2, y2, x, y),
               ts3(x1, y1, x3, y3, x, y),
               ts3(x3, y3, x2, y2, x, y)});
    return res;
}

double ts2(double x1, double y1, double x2, double y2, double x3, double y3, double m)
{
    double l = -2e4;
    double r = 2e4;
    double ans;
    while (r-l > 1e-6)
    {
        double m1 = (2*l+r)/3;
        double h1 = boris(x1, y1, x2, y2, x3, y3, m, m1);
        double m2 = (l+2*r)/3;
        double h2 = boris(x1, y1, x2, y2, x3, y3, m, m2);
        ans = (h1+h2)/2;
        if (h1 > h2)
            l = m1;
        else
            r = m2;
    }
    return ans;
}

double ts1(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double l = -2e4;
    double r = 2e4;
    double ans;
    while (r-l > 1e-6)
    {
//        cout<<l<<" "<<r<<endl;
        double m1 = (2*l+r)/3;
        double h1 = ts2(x1, y1, x2, y2, x3, y3, m1);
        double m2 = (l+2*r)/3;
        double h2 = ts2(x1, y1, x2, y2, x3, y3, m2);
        ans = (h1+h2)/2;
        if (h1 > h2)
            l = m1;
        else
            r = m2;
    }
    return ans;
}

main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    cout<<fixed<<setprecision(10);
    double x1, x2, x3, y1, y2, y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    cout<<ts1(x1, y1, x2, y2, x3, y3)<<"\n";
}