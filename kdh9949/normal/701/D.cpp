#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, v1, v2, L;

bool can(double m){
    double bus = 0, nbus = 0;
    for(int i = 0; i < (n + k - 1) / k; i++){
        if(i == 0) bus += m * v2;
        else bus += m * v1;
        nbus += m * v1;
        if(bus > L) return false;
        double sb = (bus - nbus) / (v1 + v2);
        bus += sb * v1;
        nbus += sb * v1;
    }
    return true;
}

int main(){
    scanf("%d%d%d%d%d", &n, &L, &v1, &v2, &k);
    double l = 0, r = (double)L / v2, m;
    for(int i = 0; i < 100; i++){
        m = (l + r) / 2.0;
        if(can(m)) l = m;
        else r = m;
    }
    printf("%.12f", m + (L - m * v2) / v1);
}