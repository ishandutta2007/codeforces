#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1000000000000000000LL;

struct point{
    ll x, y;
} p[100005];

ll dist(point a, point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool cmp(point a, point b){
    return a.y < b.y;
}

ll solve(int l, int r){
    if(l == r) return INF;
    int mid = (l+r)/2;
    ll d11 = solve(l, mid);
    ll d22 = solve(mid+1, r);
    ld d1 = d11;
    ld d2 = d22;
    d1 = sqrtl(d1);
    d2 = sqrtl(d2);
    vector <point> v1;
    vector <point> v2;
    for(int i=l; i<=mid; i++){
        if(p[mid].x - p[i].x <= min(d1, d2)) v1.push_back(p[i]);
    }
    for(int i=mid+1; i<=r; i++){
        if(p[i].x - p[mid].x <= min(d1, d2)) v2.push_back(p[i]);
    }
    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);
    if(d2 < d1){
        swap(d1, d2);
        swap(d11, d22);
        swap(v1, v2);
    }
    int a = v1.size();
    int b = v2.size();
    int tren = 0;
    ll d = d11;
    for(int i=0; i<a; i++){
        while((v1[i].y - v2[tren].y) > d1 && tren < b-1) tren++;
        for(int j=max(0, tren-6); j<min(b, tren+6); j++){
            d = min(d, dist(v1[i], v2[j]));
        }
    }
    return d;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    ll pref = 0;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        pref += x;
        p[i] = {i, pref};
    }
    cout << solve(1, n);
    return 0;
}