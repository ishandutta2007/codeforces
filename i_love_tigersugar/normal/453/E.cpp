//http://codeforces.com/contest/453/submission/7318455
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;

struct inode {
    int lastUsed;
};

const int BT = 131072;

inode itree[BT*2];

int s[100003],maxmana[100003],regen[100003];

long long ans[100003];
int ansi;

struct adjust
{
    int regen; // regen time
    int ansIndex;
    int l;
    int r;
};

inline bool sf(const adjust &a, const adjust &b) {
    return a.regen < b.regen;
}

vector<adjust> events;

void updateTree(int ind, int l, int r, int ql, int qr, int t, bool needUpdate = true) {
    if (r < ql || l > qr) return;
    int m = (l+r+1)>>1;
    if (ql <= l && r <= qr) {
        if (itree[ind].lastUsed < 0) {
            if (ind >= BT) {
                ans[ansi] += min(s[ind-BT] + regen[ind-BT] * (long long)t, (long long)maxmana[ind-BT]);
            } else {
                updateTree(ind<<1, l, m-1, ql, qr, t, false);
                updateTree((ind<<1)+1, m, r, ql, qr, t, false);
            }
        } else {
            adjust adj;
            adj.regen = t - itree[ind].lastUsed;
            adj.ansIndex = ansi;
            adj.l = l;
            adj.r = r;
            events.push_back(adj);
        }
        if (needUpdate) {
            itree[ind].lastUsed = t;
        }
        return;
    }
    if (itree[ind].lastUsed >= 0) {
        itree[ind<<1].lastUsed = itree[ind].lastUsed;
        itree[(ind<<1)+1].lastUsed = itree[ind].lastUsed;
        itree[ind].lastUsed = -1;
    }
    updateTree(ind<<1, l, m-1, ql, qr, t, needUpdate);
    updateTree((ind<<1)+1, m, r, ql, qr, t, needUpdate);
}

struct inode2 {
    long long bcnt;
    long long bsum;
} itree2[BT*2];

void update2(int p, long long regenrate, long long val) {
    p += BT;
    while(p) {
        itree2[p].bcnt -= regenrate;
        itree2[p].bsum += val;
        p >>= 1;
    }
}

pair<long long, long long> getBounded(int l, int r) {
    long long cnt = 0;
    long long sum = 0;
    l += BT;
    r += BT;
    while(l <= r) {
        if (l&1){
            cnt += itree2[l].bcnt;
            sum += itree2[l].bsum;
        }
        if (!(r&1)){
            cnt += itree2[r].bcnt;
            sum += itree2[r].bsum;
        }
        l = (l+1)>>1;
        r = (r-1)>>1;
    }
    return make_pair(cnt, sum);
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d",&s[i],&maxmana[i],&regen[i]);
    }
    for(int i = 0; i < BT*2; i++) {
        itree[i].lastUsed = -2;
    }
    int m;
    scanf("%d",&m);
    for(int i = 0; i < m; i++) {
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);
        l--,r--;
        ansi = i;
        updateTree(1,0,BT-1,l,r,t);
    }
    sort(events.begin(),events.end(),sf);
    vector<pair<int,int>> ponyMaxReach;
    for(int i = 0; i < n; i++) {
        if (regen[i] != 0) {
            ponyMaxReach.emplace_back((maxmana[i]+regen[i]-1) / regen[i], i);
        }
        itree2[i+BT].bcnt = regen[i];
    }
    for(int i = BT-1; i >= 1; i--) {
        itree2[i].bcnt = itree2[i<<1].bcnt + itree2[(i<<1)+1].bcnt;
    }
    sort(ponyMaxReach.begin(),ponyMaxReach.end());
    for(int i = 0, j = 0; i < events.size(); i++) {
        for(;j < ponyMaxReach.size() && ponyMaxReach[j].first <= events[i].regen;j++) {
            int ponyInd = ponyMaxReach[j].second;
            update2(ponyInd, regen[ponyInd], maxmana[ponyInd]);
        }
        auto res = getBounded(events[i].l, events[i].r);
        ans[events[i].ansIndex] += res.first * events[i].regen + res.second;
    }
    for(int i = 0; i < m; i++){
        printf("%I64d\n", ans[i]);
    }
    return 0;
}