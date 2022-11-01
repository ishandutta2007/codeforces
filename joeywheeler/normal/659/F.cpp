#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int w, h;
ll v[1005][1005];
int l[1005*1005];
int nv[1005*1005];
ll k;
ll mns;

bool lgt(int y, int x) {
    return 0 <= x && x < w && 0 <= y && y < h;
}

vector<tuple<ll,int,int> > s;

int gl(int i) {
    return i==l[i]?i:l[i]=gl(l[i]);
}

void u(int i, int j) {
    i = gl(i); j = gl(j);
    if (i-j) {
        nv[i] += nv[j];
        l[j] = i;
    }
}

bool seen[1005][1005];

void go(int y, int x) {
    if (seen[y][x] || k == 0) return;
    seen[y][x] = true;
    k -= mns;
    FO(i,0,4) {
        int ny = y+dy[i], nx = x+dx[i];
        if (lgt(ny,nx) && v[ny][nx] >= mns) go(ny,nx);
    }
}

int main() {
    scanf("%d %d %lld", &h, &w, &k);
    FO(i,0,h*w) {
        l[i] = i;
        nv[i] = 1;
    }
    FO(y,0,h) FO(x,0,w) scanf("%lld", v[y]+x);
    FO(y,0,h) FO(x,0,w) {
        s.emplace_back(-v[y][x],y,x);
    }
    sort(s.begin(),s.end());
    for (auto e : s) {
        ll val; int y, x; tie(val,y,x) = e;
        val *= -1;

        FO(i,0,4) {
            int ny = y+dy[i], nx = x+dx[i];
            if (lgt(ny,nx) && v[ny][nx] >= val) u(y*w+x,ny*w+nx);
        }
        if (k%val == 0) {
            //printf("k=%lld, val=%lld\n", k, val);
            //printf("%d\n", nv[gl(y*w+x)]);
            if (nv[gl(y*w+x)] >= k/val) {
                printf("YES\n");
                mns = val;
                go(y,x);
                FO(y,0,h) FO(x,0,w) if (seen[y][x]) v[y][x] = val;
                else v[y][x] = 0;
                FO(y,0,h) FO(x,0,w) printf("%lld%c", v[y][x], " \n"[x+1==w]);
                return 0;
            }
        }
    }
    printf("NO\n");
}