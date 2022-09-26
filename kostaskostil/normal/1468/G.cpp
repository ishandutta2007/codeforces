#include<bits/stdc++.h>
#define ll long long
#define point pair<ll, ll>
#define double_point pair<double, double>
#define x first
#define y second

using namespace std;

const int N = 2e5+1;

struct line{
    ll a, b, c;
    ll operator()(point p){
        return a * p.x + b * p.y + c;
    }
};

int n, H;
point p[N];

line get_line(point a, point b){
    line l;
    l.a = b.y - a.y;
    l.b = a.x - b.x;
    l.c = -l.a*a.x - l.b*a.y;
    if(l.b < 0){
        l.a = -l.a;
        l.b = -l.b;
        l.c = -l.c;
    }
    return l;
}

double_point intersection(line a, line b){
    double_point p;
    p.y = (1.0 * b.c * a.a - a.c * b.a)/(a.b * b.a - b.b * a.a);
    p.x = -(1.0 * b.c * a.b - a.c * b.b)/(a.b * b.a - b.b * a.a);
    return p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cout << fixed << setprecision(10);
    cin >> n >> H;
    for(int i = 0; i < n; ++i)
        cin >> p[i].x >> p[i].y;
    point pH = {p[n-1].x, p[n-1].y + H};
    double ans = hypot(p[n-1].x - p[n-2].x, p[n-1].y - p[n-2].y);
    point last_p = p[n-2];
    for(int i = n-3; i >= 0; --i){
        line l = get_line(pH, last_p);
        if(l(p[i]) < 0)
            continue;
        if(l(p[i]) == 0){
            if(l(p[i+1]) == 0)
                ans += hypot(p[i+1].x - p[i].x, p[i+1].y - p[i].y);
            continue;
        }
        double_point ip = intersection(l, get_line(p[i+1], p[i]));
        ans += hypot(p[i].x - ip.x, p[i].y - ip.y);
        last_p = p[i];
    }
    cout << ans << "\n";
}