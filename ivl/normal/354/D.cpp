#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
#include <assert.h>
#include <map>
#include <cstring>
#include <bitset>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int Enum(int a, int b){
    return a * 100002 + b;
}

const int oo = 1000000000;

int n, k;
pii in[100005];

bitset < 780 * 100005 > B;

int main(){
    scanf("%d%d", &n, &k);
    int R = 0;
    REP(k,i){
        scanf("%d%d", &in[i].x, &in[i].y);
        int r = n+1 - in[i].x;
        if (r > 775) R += 3;
        else {
            --r; // r < 775
            --in[i].y;
            int t = Enum(r, in[i].y);
            B[t] = 1;
        }
    }
    vector < int > V1(776);
    for (int c = n-1; c >= 0; --c){
        vector < int > V2(776);
        int Tmp = oo;
        int Cnt = 0;
        for (int r = 775; r >= 0; --r){
            if (r == 0){
                V2[0] = min(Tmp, Cnt * 3 + V1[0]);
            } else {
                V2[r] = min(Tmp, Cnt * 3 + V1[r-1]);
                Cnt += B[Enum(r-1, c)]; //TRACE(r);
            } Tmp = min(Tmp, V2[r] + r * (r + 1) / 2 + 2);
        } swap(V1, V2);
    } printf("%d\n", R + V1[0]);
    return 0;
}