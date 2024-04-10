#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ld ml=0.000000001;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    ld a, b, m;
    cin >> a >> b >> m;
    ld vx, vy, vz;
    cin >> vx >> vy >> vz;
    vz = abs(vz);
    ld t = m/(-vy);
    /// z
    ld sz = vz*t;
    ld pocz=0;
    while(sz > b){
        if(pocz < ml) pocz = b;
        else pocz = 0;
        sz -= b;
    }
    if(abs(pocz-b) < ml){
        pocz -= sz;
    }
    else pocz = sz;
    /// x
    ld pocx = a/2;
    ld sx = abs(vx)*t;
    if(sx < a/2){
        if(vx < 0) pocx -= sx;
        else pocx += sx;
        cout << pocx << " " << pocz << endl;
        return 0;
    }
    else{
        sx -= a/2;
        if(vx < 0) pocx = 0;
        else pocx = a;
    }
    while(sx > a){
        if(pocx <= ml) pocx = a;
        else pocx = 0;
        sx -= a;
    }
    if(pocx <= ml) pocx += sx;
    else pocx -= sx;
    cout << pocx << " " << pocz << endl;
    return 0;
}