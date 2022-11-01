#include <bits/stdc++.h>

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

int main(){
    ll a, b;
    cin >> a >> b;
    if (a < b){cout << "-1\n"; return 0;}
    int tp = (a+b*2-1) / (b*2) - 1;
    if (a%(2*b) < b && a%b != 0) --tp;
    printf("%.12lf\n", (double)(a+b) / (2*tp+2));
    return 0;
}