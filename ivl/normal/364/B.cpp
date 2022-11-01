#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define ll long long
#define pll pair < ll, ll >
#define x first
#define y second
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, d;
int c[55];

bitset < 600005 > ex;

int Next(int x){
    while (!ex[x]) --x;
    return x;
}

int main(){
    cin >> n >> d;
    REP(n,i) cin >> c[i];

    ex[0] = 1;
    REP(n,i) ex |= (ex << c[i]);

    int A = 0, B = 0;
    for (int C = Next(A+d); C != A; A = C, ++B, C = Next(A+d));
    cout << A << " " << B << endl;

    return 0;
}