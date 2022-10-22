#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[5];
int y[5];

int match(int b1, int b2){
    if(x[b1] == x[b2]) return 1;
    if(y[b1] == y[b2]) return 2;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    cin >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3];
    if(match(1,2) && match(1,3) && match(2, 3)){cout << 1; return 0;}
    int minres = 3;
    int nis=0;
    if(match(1,2) == 1){
        nis = 0;
        if(y[3] < y[1] && y[3] > y[2]) nis=1;
        if(y[3] > y[1] && y[3] < y[2]) nis=1;
        if(nis == 0) minres = 2;
    }
    if(match(1,3) == 1){
        nis = 0;
        if(y[2] < y[1] && y[2] > y[3]) nis=1;
        if(y[2] > y[1] && y[2] < y[3]) nis=1;
        if(nis == 0) minres = 2;
    }
    if(match(2,3) == 1){
        nis = 0;
        if(y[1] < y[3] && y[1] > y[2]) nis=1;
        if(y[1] > y[3] && y[1] < y[2]) nis=1;
        if(nis == 0) minres = 2;
    }
    if(match(1,2) == 2){
        nis = 0;
        if(x[3] < x[1] && x[3] > x[2]) nis=1;
        if(x[3] > x[1] && x[3] < x[2]) nis=1;
        if(nis == 0) minres = 2;
    }
    if(match(1,3) == 2){
        nis = 0;
        if(x[2] < x[1] && x[2] > x[3]) nis=1;
        if(x[2] > x[1] && x[2] < x[3]) nis=1;
        if(nis == 0) minres = 2;
    }
    if(match(2,3) == 2){
        nis = 0;
        if(x[1] < x[3] && x[1] > x[2]) nis=1;
        if(x[1] > x[3] && x[1] < x[2]) nis=1;
        if(nis == 0) minres = 2;
    }
    cout << minres;
    return 0;
}