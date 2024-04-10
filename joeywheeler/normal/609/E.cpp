#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int l[200005];

int gl(int i) {
    return i == l[i] ? i : l[i] = gl(l[i]);
}

int n, m;
tuple<int,int,int,int> t[200005];
tuple<int,int,int> tr[200005];
int ts = 0;
int s[200005], e[200005];
vector<int> ops[200005];
long long b[200005]; int W[200005];
long long sw;

int main() {
    scanf("%d%d", &n, &m);
    FO(i,0,m) {
        int x, y, w; scanf("%d%d%d", &x, &y, &w);
        t[i] = make_tuple(w,x,y,i);
        W[i] = w;
    }
    sort(t,t+m);
    FO(i,1,n+1) l[i] = i;
    FO(j,0,m) {
        int x, y, w, i; tie(w,x,y,i) = t[j];
        if (gl(x) != gl(y)) {
            tr[ts++] = make_tuple(x,y,w);
            l[gl(x)] = gl(y);
            sw += w;
        }
    }
    FO(i,0,m) s[i] = 0, e[i] = n-2;
    while (1) {
        bool done = true;
        FO(i,0,n) ops[i].clear();
        FO(i,0,m) if (s[i] <= e[i]) {
            done = false;
            int md = (s[i]+e[i])/2;
            ops[md].push_back(i);
        }
        if (done) break;
        FO(i,1,n+1) l[i] = i;
        FO(ct,0,n-1) {
            int xx, yy, ww; tie(xx,yy,ww) = tr[ct];
            l[gl(xx)] = gl(yy);
            for (int i : ops[ct]) {
                int w, x, y, ind; tie(w,x,y,ind) = t[i];
                if (gl(x) == gl(y)) {
                    b[ind] = sw + w - ww;
                    e[i] = ct-1;
                } else {
                    s[i] = ct+1;
                }
            }
        }
    }
    FO(i,0,m) printf("%lld\n", b[i]);
}