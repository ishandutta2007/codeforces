#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 6000;

int x[N+5];
int y[N+5];

short sve[4][4][4][4][4];
short daje[N+5][4][4][4][4][4];

void calc(int ind){
    for(int xi=0; xi<4; xi+=2){
        for(int xj=0; xj<4; xj+=2){
            for(int yi=0; yi<4; yi+=2){
                for(int yj=0; yj<4; yj+=2){
                    ll g = y[ind]*(xi-xj) + x[ind]*(yj-yi);
                    g += __gcd(x[ind] - xi, y[ind] - yi);
                    g += __gcd(x[ind] - xj, y[ind] - yj);
                    g %= 4;
                    if(g < 0) g += 4;
                    daje[ind][xi][yi][xj][yj][g]++;
                }
            }
        }
    }
}

void dodaj(int ind, int k){
    for(int xi=0; xi<4; xi+=2){
        for(int xj=0; xj<4; xj+=2){
            for(int yi=0; yi<4; yi+=2){
                for(int yj=0; yj<4; yj+=2){
                    for(int res=0; res<4; res+=2){
                        sve[xi][yi][xj][yj][res] += k*daje[ind][xi][yi][xj][yj][res];
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
        calc(i);
        dodaj(i, 1);
    }
    ll res = 0;
    for(int i=1; i<=n; i++){
        dodaj(i, -1);
        int xi = x[i]%4;
        xi %= 4;
        if(xi < 0) xi += 4;
        int yi = y[i]%4;
        yi %= 4;
        if(yi < 0) yi += 4;
        for(int j=i+1; j<=n; j++){
            dodaj(j, -1);
            int xj = x[j]%4;
            xj %= 4;
            if(xj < 0) xj += 4;
            int yj = y[j]%4;
            yj %= 4;
            if(yj < 0) yj += 4;
            short sad = xi*yj - xj*yi;
            sad -= __gcd(xi - xj, yi - yj);
            sad %= 4;
            if(sad < 0) sad += 4;
            res += sve[xi][yi][xj][yj][sad];
            dodaj(j, 1);
        }
        dodaj(i, 1);
    }
    cout << res/3 << "\n";
    return 0;
}