#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second
#define real long double
#define point pair < real, real >

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

const real ep = 1e-12;

class line{
public:
    ll a, b, c;
};

bool parallel(line a, line b){
    return a.a * b.b == a.b * b.a;
}

point intersection(line a, line b){
    return {(real)(a.b * b.c - a.c * b.b) / (a.a * b.b - a.b * b.a), (real)(a.a * b.c - a.c * b.a) / (a.b * b.a - a.a * b.b)};
}

bool element(line a, point b){
    return fabs(a.a * b.x + a.b * b.y + a.c) < ep;
}

int count(vector < pair < line, int > > V, point t){
    int R = 0;
    for (auto x : V) if (element(x.x, t)) ++R;
    return R;
}

vector < pair < line, int > > remove(vector < pair < line, int > > V, point t){
    vector < pair < line, int > > R;
    for (auto x : V) if (!element(x.x, t)) R.pb(x);
    return R;
}

int n, k;

bool Solve(vector < pair < line, int > > V, int k){
    if ((int)V.size() <= k){
        printf("YES\n%d\n", ::k);
        for (auto x : V) printf("%d -1\n", x.y);
        REP(k-V.size(),i) printf("1 -1\n");
        return true;
    }
    if (k == 0) return false;

    if ((int)V.size() > k*k){
        REP(k*k+1,i) REP(i,j) if (!parallel(V[i].x, V[j].x)) if (count(V, intersection(V[i].x, V[j].x)) > k){
            if (!Solve(remove(V, intersection(V[i].x, V[j].x)), k-1)) return false;
            printf("%d %d\n", V[i].y, V[j].y);
            return true;
        } return false;
    } else {
        REP(V.size(),i) REP(i,j) if (!parallel(V[i].x, V[j].x)) if (count(V, intersection(V[i].x, V[j].x)) >= (V.size() + k-1) / k){
            if (!Solve(remove(V, intersection(V[i].x, V[j].x)), k-1)) continue;
            printf("%d %d\n", V[i].y, V[j].y);
            return true;
        } return false;
    }
}

int main(){
    scanf("%d%d", &n, &k);
    vector < pair < line, int > > V;
    REP(n,i){
        ll a, b, c;
        cin >> a >> b >> c;
        V.pb({{a, b, c}, i+1});
    }
    if (!Solve(V, k)) printf("NO\n");
    return 0;
}