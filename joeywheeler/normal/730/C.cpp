#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

struct shop {
    int p, numShovels, price;
    shop (int _p=0, int _numShovels=0, int _price=0) : p(_p), numShovels(_numShovels), price(_price) {}
    bool operator < (const shop &_s) const {
        return price < _s.price;
    }
};
vector <shop> allShops;

int N, S, Q, E;
vector <int> allE[5005];
bool seen[5005];
int dist[5005][5005];


int qCity, qShovels, qBudget;
bool canDo (int t) {
    int leftAm = qShovels;
    ll leftBudget = qBudget;
    FO (i,0,allShops.size()) {
        if (dist[qCity][allShops[i].p] > t) continue;
        leftBudget -= (long long)allShops[i].price * min(leftAm, allShops[i].numShovels);
        leftAm = max (0, leftAm-allShops[i].numShovels);
        if (leftAm == 0) break;
    }
    if (leftBudget < 0 || leftAm > 0) return false;
    return true;
}

int main() {
    scanf ("%d %d", &N, &E);
    FO (i,0,E) {
        int _x, _y;
        scanf ("%d %d", &_x, &_y);
        _x--; _y--;
        allE[_x].push_back (_y);
        allE[_y].push_back (_x);
    }
    FO (i,0,N) {
        memset (seen, 0, sizeof(seen));
        queue <int> q;
        FO (p,0,N) dist[i][p] = 123456789;
        dist[i][i] = 0;
        q.push (i);
        seen[i] = true;
        while (!q.empty()) {
            int cNode = q.front();
            q.pop();
            for (int nNode : allE[cNode]) {
                if (seen[nNode]) continue;
                seen[nNode] = true;
                dist[i][nNode] = dist[i][cNode]+1;
                q.push (nNode);
            }
        }
    }
    scanf ("%d", &S);
    FO (i,0,S) {
        int _c, _k, _p;
        scanf ("%d %d %d", &_c, &_k, &_p);
        _c--;
        allShops.push_back (shop (_c, _k, _p));
    }
    sort (allShops.begin(), allShops.end());
    scanf ("%d", &Q);
    FO (_q,0,Q) {
        scanf ("%d %d %d", &qCity, &qShovels, &qBudget);
        qCity--;
        int lo = 0;
        int hi = N+5;
        int mid;
        int bSoFar = -1;
        while (lo <= hi) {
            mid = (lo+hi)/2;
            if (canDo(mid)) {
                bSoFar = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        if (bSoFar == -1) {
            printf ("-1\n");
        } else {
            printf ("%d\n", bSoFar);
        }
    }
    return 0;
}