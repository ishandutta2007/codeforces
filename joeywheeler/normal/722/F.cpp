#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int cf[45], nc[45];
vector<int> ppf[45];

bool canadd(int i, int m) {
    for (int p : ppf[m]) {
        if (nc[p] && cf[p] != i % p) return false;
    }
    return true;
}

void add(int i, int m) {
    for (int p : ppf[m]) {
        if (nc[p] == 0) cf[p] = i % p;
        nc[p]++;
    }
}

void rem(int m) {
    for (int p : ppf[m]) {
        nc[p]--;
    }
}

vector<pair<int,int> > loc[100005];
int k[100005];
int n, m;

int main() {
    FO(i,2,45) {
        int x = i;
        //printf("%d:", i);
        FO(j,2,45) {
            int fct = 1;
            while (x%j == 0) {
                fct *= j;
                ppf[i].push_back(fct);
                //printf(" %d", fct);
                x /= j;
            }
        }
        //printf("\n");
    }

    scanf("%d %d", &n, &m);
    FO(i,0,n) {
        scanf("%d", k+i);
        FO(j,0,k[i]) {
            int x; scanf("%d", &x);
            loc[x].push_back(make_pair(i,j));
        }
    }

    FO(x,1,m+1) {
        queue<pair<int,int> > cq;
        int prv = -1, ans = 0;
        for (auto l : loc[x]) {
            int i, j; tie(i,j) = l;
            if (i != prv+1) {
                while (sz(cq)) {
                    int fi, fj; tie(fi, fj) = cq.front(); cq.pop();
                    rem(k[fi]);
                }
            }
            while (!canadd(j, k[i])) {
                //printf("sz(cq) = %d\n", sz(cq));
                int fi, fj; tie(fi, fj) = cq.front(); cq.pop();
                rem(k[fi]);
            }
            add(j, k[i]);
            cq.emplace(i, j);
            prv = i;
            ans = max(ans, sz(cq));
        }
        while (sz(cq)) {
            int fi, fj; tie(fi, fj) = cq.front(); cq.pop();
            rem(k[fi]);
        }
        printf("%d\n", ans);
    }
}