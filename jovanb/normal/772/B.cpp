#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int n;

struct pt{
    ld x;
    ld y;
} niz[100005];

ld dist(pt a, pt b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

ld vis(pt a, pt b, pt c){
    return abs((b.y-a.y)*c.x-(b.x-a.x)*c.y+b.x*a.y-b.y*a.x)/(dist(a,b));
}

int main(){
    cout.precision(10);
    cout << fixed;

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i].x >> niz[i].y;
    }
    ld mx=1e17;
    for(int i=1; i<=n; i++){
        int a = i;
        int b = i+1;
        int c = i+2;
        if(c > n) c -= n;
        if(b > n) b -= n;
        mx = min(mx, vis(niz[a], niz[b], niz[c]));
        mx = min(mx, vis(niz[b], niz[c], niz[a]));
        mx = min(mx, vis(niz[c], niz[a], niz[b]));
    }
    cout << mx/2;
    return 0;
}