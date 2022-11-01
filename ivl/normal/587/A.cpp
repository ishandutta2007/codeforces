#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
int c[2000005];

int main(){
    cin >> n;
    REP(n,i){
        int x;
        scanf("%d", &x);
        ++c[x];
    }
    int R = 0;
    REP(2000000,i){
        R += c[i]%2;
        c[i+1] += c[i]/2;
    } cout << R << endl;
    return 0;
}