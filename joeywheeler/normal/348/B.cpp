#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

vector<int> u[100005];
int n, a[100005];
ll mxv = 1e14, mv=1, s;

ll mul(ll a, ll b) {
    if (a * 1. * b > 1e14) {
        return 1e14;
    } else {
        return a*b;
    }
}

ll gcd(ll a, ll b) {
    return a ? gcd(b%a,a) : b;
}

ll lcm(ll a, ll b) {
    return mul(a / gcd(a,b), b);
}

void go(int i, int p, ll cd) {
    if (sz(u[i])-(p!=-1) == 0) {
        mxv = min(mxv, mul(cd,a[i]));
        mv = lcm(mv,cd);
    } else {
        if (mul(cd,sz(u[i])-(p!=-1)) >= 5e13) {
            printf("%lld\n", s);
            exit(0);
        }
        cd *= sz(u[i])-(p!=-1);
        for (int j : u[i]) if (j != p) {
            go(j, i, cd);
        }
    }
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", a+i), s+=a[i];
    FO(i,0,n-1) {
        int x,y; scanf("%d%d", &x, &y); x--; y--;
        u[x].push_back(y); u[y].push_back(x);
    }
    go(0,-1,1);
    printf("%lld\n", s - (mxv/mv)*mv);
}