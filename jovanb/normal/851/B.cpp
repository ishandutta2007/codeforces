#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct Point{
    ll x, y;
};

ll dist(Point a, Point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

ll rot(Point a, Point b, Point c){
    return (c.y-a.y)*(b.x-a.x) - (c.x-a.x)*(b.y-a.y);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    Point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    if(dist(a, b) != dist(b, c) || rot(a, b, c) == 0) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}