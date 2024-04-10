#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<int> u[3005];
int sp[3005][3005];
int n, m;
vector<pair<int,int> > fin[3005];
vector<pair<int,int> > fout[3005];

int p[4];

int bp[4];
int bl;

void upd() {
    int l = 0;
    FO(i,0,3) l += sp[p[i]][p[i+1]];
    if (l > bl) {
        FO(i,1,4) FO(j,0,i) if (p[i] == p[j]) return;
        FO(i,0,4) bp[i] = p[i];
        bl = l;
    }
}

int q[3005], qs, qe;

int main() {
    scanf("%d%d", &n, &m);
    FO(z,0,m) {
        int x, y; scanf("%d%d", &x, &y); x--; y--;
        u[x].push_back(y);
    }
    FO(i,0,n) {
        FO(j,0,n) sp[i][j] = 1e5;
        qs = qe = 0;
        q[qe++] = i;
        sp[i][i] = 0;
        while (qs != qe) {
            int f = q[qs++];
            for (int j : u[f]) {
                if (sp[i][j] > 1e4) {
                    sp[i][j] = sp[i][f]+1;
                    q[qe++] = j;
                }
            }
        }
    }
    FO(i,0,n) {
        FO(j,0,n) if (j != i && sp[j][i] < 1e4) {
            fin[i].emplace_back(sp[j][i],j);
            if (sz(fin[i]) > 3) {
                sort(fin[i].begin(),fin[i].end());
                fin[i].erase(fin[i].begin());
            }
        }

        FO(j,0,n) if (j != i && sp[i][j] < 1e4) {
            fout[i].emplace_back(sp[i][j],j);
            if (sz(fout[i]) > 3) {
                sort(fout[i].begin(),fout[i].end());
                fout[i].erase(fout[i].begin());
            }
        }
    }

    FO(i,0,n) FO(j,0,n) if (i != j && sp[i][j] < 1e4) {
        p[1] = i;
        p[2] = j;
        for (auto &f : fin[i]) for (auto &e : fout[j]) {
            p[0] = f.second;
            p[3] = e.second;
            upd();
        }
    }
    FO(i,0,4) printf("%d%c", 1+bp[i], " \n"[i==3]);
}