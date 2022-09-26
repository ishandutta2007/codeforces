
#include <bits/stdc++.h>
 
#define fi first
#define se second
#define pb push_back
 
using namespace std;
 
const int nmax=1000500;
typedef long long ll;
#define int ll
 
istream& operator >> (istream& is, vector<int>& v)
{
    for (int& i:v) is>>i;
    return is;
}
 
const int inf = 2e6;
int a, b, c, d;
 
int summit(int t, int l, int r);
int f_pref(int t, int r) /// sum(min(t, [i / d])) for i = 0 to r
{
    int rem = r % d;
 
    int s = (rem+1) * min(t, r/d);
    r-=rem;
    r/=d;
    r--;
 
    if (r<=0)
        return s;
 
    /// d*sum(min(t, r)) left
 
//    int sqr = min(t, r);
//    s += d*((sqr * (sqr+1))/2);
//    if (r > sqr)
//        s += d*((r-sqr) * t);
    s+=d*summit(t, 0, r);
 
    return s;
}
 
int summin(int t, int r) /// sum(min(t, i)) for i = 0 to r
{
    if (r<=0) return 0;
    int sqr = min(t, r);
    int s = sqr*(sqr+1)/2;
    if (r > sqr)
        s+=t*(r-sqr);
    return s;
}
 
int summit(int t, int l, int r)
{
    return summin(t, r)-summin(t, l-1);
}
 
int sumsquares(int r)
{
    return r*(r+1)*(2*r+1)/6;
}
 
int doublemin(int a, int b)
{
    if (a>b)
        swap(a, b);
    int s=0;
//    for (int i=1; i<=a; i++)
//        s+=i*(2*a - 2*i + 1);
    s+=2*a*a*(a+1)/2;
    s-=2*sumsquares(a);
    s+=a*(a+1)/2;
 
//    for (int i=1; i<=a; i++)
    s+=(b-a)*a*(a+1)/2;
 
    return s;
}
 
int g_pref(int x, int r)
{
    int rem = r % d;
 
    int s=0;
//    for (int t=0; t<x; t++)
//        s += (rem+1) * min(t, r/d);
    s += (rem+1) * summit(r/d, 0, x-1);
    r-=rem;
    r/=d;
    r--;
 
    if (r<=0)
        return s;
 
    /// for t = [0, x-1] ; i = [0, r] : sum(min(i, t));
 
//    for (int t = 0; t<x; t++)
//        for (int i=0; i<=r; i++)
//            s+=d*min(i, t);
 
    s+=d*doublemin(x-1, r);
//        s+=d*summit(t, 0, r);
 
    return s;
}
 
int f(int t) /// sum( min(t, [(c+i) / d]) ) for i = 0 to (d-1)
{
//    int s = 0;
//    for (int i=0; i<=d-1; i++)
//        s+=min(t, (c+i)/d);
//
//    if (s!= f_pref(t, c+d-1) - f_pref(t, c-1))
//        cout<<t<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<s<<" "<<f_pref(t, c+d-1)<<" "<<f_pref(t, c-1)<<"\n";
//    return s;
 
    return f_pref(t, c+d-1) - f_pref(t, c-1);
}
 
int dmg(int x) /// sum( b*f(i) ) for i = 1 to x-1
{
//    int s = a*x;
//    for (int i=0; i<=x-1; i++)
//        s-=b*f(i);
    return a*x - (b*(g_pref(x, c+d-1) - g_pref(x, c-1)));
}
 
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>a>>b>>c>>d;
 
        if (a > b*c)
            cout<<-1<<"\n";
        else if (a == b*c)
            cout<<dmg(inf)<<"\n";
        else
        {
            int l = 0;
            int r = inf;
            while (l + 10 < r)
            {
                int m1 = (2*l + r)/3;
                int m2 = (l + 2*r)/3;
 
                int t1 = dmg(m1);
                int t2 = dmg(m2);
                if (t1 < t2)
                    l = m1;
                else
                    r = m2;
            }
            int mx = 0;
            for (int i = l; i<=r; i++)
//            for (int i=1; i<=1000; i++)
                mx = max(mx, dmg(i));
            cout<<mx<<"\n";
        }
    }
}