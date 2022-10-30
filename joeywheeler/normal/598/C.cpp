#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

struct p {
    ll x, y;
    int i;
};

struct Frac {
    ll num, denom;
    int i, j;

    Frac(ll x=0, ll y=1) : num(x), denom(y) {
        simplify();
    }

    void simplify() {
        ll a = abs(num), b = abs(denom), t;
        //printf("%lld %lld\n", num, denom);
        while (a) {
            t = a;
            a = b%a;
            b = t;
        }
        num /= b; denom /= b;

        if (denom < 0) {
            num *= -1;
            denom *= -1;
        }
    }

    Frac operator-() {
        return Frac(-num, denom);
    }

    bool operator<(Frac o) {
        simplify(); o.simplify();
        if (num < 0 && o.num < 0) {
            return -o < -*this;
        } else if (num < 0) {
            return true;
        } else if (o.num < 0) {
            return false;
        } else {
            Frac a = *this, b = o;
            while (1) {
                ll A = a.num/a.denom, B = b.num/b.denom;
                if (A != B) return A < B;

                a.num %= a.denom; b.num %= b.denom;
                if (a.num == 0) {
                    return b.num > 0;
                } else if (b.num == 0) {
                    return false;
                }
                swap(a.num,a.denom); swap(b.num,b.denom);
                swap(a,b);
            }
        }
    }
};

bool cmp(p a, p b) {
    bool au = a.y > 0 || (a.y == 0 && a.x >= 0);
    bool bu = b.y > 0 || (b.y == 0 && b.x >= 0);
    if (au != bu) {
        return au;
    }
    ll v = a.x * b.y - a.y * b.x;
    if (v == 0) return false;
    if (v < 0) return false;
    if (v > 0) return true;
    assert(false);
    return false;
}

int n;
p l[100005];

#define sq(x) ((x)*(x))
#define fsq(x) (abs(x)*(x))

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%lld %lld", &l[i].x, &l[i].y);
        l[i].i = i;
    }
    sort(l,l+n,cmp);
    FO(i,0,n) {
        //printf("(%lld,%lld)\n", l[i].x, l[i].y);
    }
    Frac mn(fsq(l[n-1].x*l[0].x+l[n-1].y*l[0].y), (sq(l[n-1].x)+sq(l[n-1].y))*(sq(l[0].x)+sq(l[0].y)));
    mn.i = n-1, mn.j = 0;
    FO(i,0,n-1) {
        Frac a(fsq(l[i].x*l[i+1].x+l[i].y*l[i+1].y), (sq(l[i].x)+sq(l[i].y))*(sq(l[i+1].x)+sq(l[i+1].y)));
        a.i = i; a.j = i+1;
        if (mn < a) mn = a;
    }
    //printf("%d %d\n", mn.i, mn.j);
    printf("%d %d\n", l[mn.i].i+1, l[mn.j].i+1);
}