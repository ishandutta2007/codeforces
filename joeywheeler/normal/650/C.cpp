#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int POOL[2000005];

int h, w;
int mxr[1000005];
int mxc[1000005];
int **g;

pair<int,int> sv[1000005];
int l[1000005];
int la[1000005];

int gl(int i) {
    if (l[i] == i) {
        return i;
    } else {
        return l[i] = gl(l[i]);
    }
}

void u(int i, int j) {
    l[gl(i)] = gl(j);
}

int main() {
    scanf("%d%d", &h, &w);
    g = new int*[h];

    FO(i,0,h) g[i] = &POOL[w*i];
    FO(y,0,h) FO(x,0,w) {
        scanf("%d", &g[y][x]);
    }

    FO(i,0,w*h) l[i] = i;

    FO(y,0,h) {
        FO(x,0,w) {
            sv[x] = make_pair(g[y][x], y*w+x);
        }
        sort(sv,sv+w);
        FO(i,1,w) {
            if (sv[i].first == sv[i-1].first) u(sv[i].second, sv[i-1].second);
        }
    }
    FO(x,0,w) {
        FO(y,0,h) {
            sv[y] = make_pair(g[y][x], y*w+x);
        }
        sort(sv,sv+h);
        FO(i,1,h) {
            if (sv[i].first == sv[i-1].first) u(sv[i].second, sv[i-1].second);
        }
    }
    FO(y,0,h) FO(x,0,w) sv[y*w+x] = make_pair(g[y][x], y*w+x);
    sort(sv,sv+h*w);

    for (int i = 0; i < h*w;) {
        int j;
        for (j = i; j < h*w && sv[j].first == sv[i].first; j++) {
            int y = sv[j].second/w;
            int x = sv[j].second%w;
            int val = max(mxr[y], mxc[x])+1;
            int ld = gl(sv[j].second);
            la[ld] = max(la[ld], val);
        }
        for (j = i; j < h*w && sv[j].first == sv[i].first; j++) {
            int y = sv[j].second/w;
            int x = sv[j].second%w;
            int ld = gl(sv[j].second);
            int val = la[ld];
            g[y][x] = val;
            mxr[y] = max(mxr[y], val);
            mxc[x] = max(mxc[x], val);
        }
        i = j;
    }
    FO(y,0,h) FO(x,0,w) printf("%d%c", g[y][x], " \n"[x+1==w]);
}