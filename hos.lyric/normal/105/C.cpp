//  Codeforces Beta Round #81

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

const int L = 10;

int N;
string nameI[1010];
string clasI[1010];
int P[1010][3];
int sz[1010];

int K;
string nameR[1010];
string typeR[1010];
int bonus[1010];
string home[1010];

vector<vint> residents;
int clas[1010];
int type[1010];

pair<int,pint> dp[1010][12][12][12];
bool prev[1010][12][12][12];

int used[1010];
vector<vint> ans;

void dping() {
    int j, k;
    int xs[3], ys[3];
    pair<int,pint> p;
    
    memset(dp, 0, sizeof(dp));
    memset(prev, 0, sizeof(prev));
    for (k = 0; k < K; ++k) {
        for (xs[0] = 0; xs[0] <= L; ++xs[0]) 
        for (xs[1] = 0; xs[1] <= L; ++xs[1]) 
        for (xs[2] = 0; xs[2] <= L; ++xs[2]) 
        {
            p = dp[k][xs[0]][xs[1]][xs[2]];
            for (j = 0; j < 3; ++j) {
                ys[j] = xs[j];
            }
            if (dp[k + 1][ys[0]][ys[1]][ys[2]] < p) {
                dp[k + 1][ys[0]][ys[1]][ys[2]] = p;
                prev[k + 1][ys[0]][ys[1]][ys[2]] = 0;
            }
            ++ys[type[k]];
            if (type[k] == 0) p.first         += bonus[k];
            if (type[k] == 1) p.second.first  += bonus[k];
            if (type[k] == 2) p.second.second += bonus[k];
            if (dp[k + 1][ys[0]][ys[1]][ys[2]] < p) {
                dp[k + 1][ys[0]][ys[1]][ys[2]] = p;
                prev[k + 1][ys[0]][ys[1]][ys[2]] = 1;
            }
        }
    }
}
void recover(int is[]) {
    int j, k;
    int xs[3];
    for (j = 0; j < 3; ++j) {
        xs[j] = sz[is[j]];
    }
    for (k = K; k > 0; ) {
        bool prv = prev[k][xs[0]][xs[1]][xs[2]];
        --k;
        if (prv) {
            used[k] = type[k];
            --xs[type[k]];
        } else {
            used[k] = -1;
        }
    }
}
void makeAnswer(int is[]) {
//cout<<"used : ";pv(used,used+K);
    int j, k;
for(j=0;j<3;++j)assert(is[j]<N);
    ans = vector<vint>(3, vint());
    for (k = 0; k < K; ++k) if (~used[k]) {
        ans[used[k]].push_back(k);
    }
//*
    for (k = 0; k < K; ++k) if (!~used[k]) {
        for (j = 0; j < 3; ++j) {
            if ((int)ans[j].size() < sz[is[j]]) {
                ans[j].push_back(k);
                break;
            }
        }
    }
//*/
for(j=0;j<3;++j)assert((int)ans[j].size()<=sz[is[j]]);
    for (j = 0; j < 3; ++j) {
        printf("%s %u", nameI[is[j]].c_str(), ans[j].size());
        for (uint l = 0; l < ans[j].size(); ++l) {
            printf(" %s", nameR[ans[j][l]].c_str());
        }
        puts("");
    }
}
void takeMax() {
    int is[3];
    pair<int,pint> dai = mp(-1, mp(-1, -1)), tmp;
    for (is[0] = 0; is[0] < N; ++is[0]) if (clas[is[0]] == 0) 
    for (is[1] = 0; is[1] < N; ++is[1]) if (clas[is[1]] == 1) 
    for (is[2] = 0; is[2] < N; ++is[2]) if (clas[is[2]] == 2) 
    {
        tmp = dp[K][sz[is[0]]][sz[is[1]]][sz[is[2]]];
        tmp.first         += P[is[0]][0];
        tmp.second.first  += P[is[1]][1];
        tmp.second.second += P[is[2]][2];
//cout<<"tmp = "<<tmp.first<<" "<<tmp.second.first<<" "<<tmp.second.second<<endl;
        chmax(dai, tmp);
    }
//cout<<"dai = "<<dai.first<<" "<<dai.second.first<<" "<<dai.second.second<<endl;
    for (is[0] = 0; is[0] < N; ++is[0]) if (clas[is[0]] == 0) 
    for (is[1] = 0; is[1] < N; ++is[1]) if (clas[is[1]] == 1) 
    for (is[2] = 0; is[2] < N; ++is[2]) if (clas[is[2]] == 2) 
    {
        tmp = dp[K][sz[is[0]]][sz[is[1]]][sz[is[2]]];
        tmp.first         += P[is[0]][0];
        tmp.second.first  += P[is[1]][1];
        tmp.second.second += P[is[2]][2];
        if (dai == tmp) {
//cout<<"is : ";pv(is,is+3);
            recover(is);
            makeAnswer(is);
            return;
        }
    }
}

int pts[1010];
void solveSpecial() {
    int i, j, k;
    for (i = 0; i < N; ++i) {
        pts[i] = P[i][clas[i]];
        for (uint l = 0; l < residents[i].size(); ++l) {
            k = residents[i][l];
            if (clas[i] == type[k]) {
                pts[i] += bonus[k];
            }
        }
    }
    int is[3];
    pair<int,pint> dai = mp(-1, mp(-1, -1)), tmp;
    for (is[0] = 0; is[0] < N; ++is[0]) if (clas[is[0]] == 0) 
    for (is[1] = 0; is[1] < N; ++is[1]) if (clas[is[1]] == 1) 
    for (is[2] = 0; is[2] < N; ++is[2]) if (clas[is[2]] == 2) 
    {
        tmp = mp(pts[is[0]], mp(pts[is[1]], pts[is[2]]));
        chmax(dai, tmp);
    }
//cout<<"dai = "<<dai.first<<" "<<dai.second.first<<" "<<dai.second.second<<endl;
    for (is[0] = 0; is[0] < N; ++is[0]) if (clas[is[0]] == 0) 
    for (is[1] = 0; is[1] < N; ++is[1]) if (clas[is[1]] == 1) 
    for (is[2] = 0; is[2] < N; ++is[2]) if (clas[is[2]] == 2) 
    {
        tmp = mp(pts[is[0]], mp(pts[is[1]], pts[is[2]]));
        if (dai == tmp) {
//cout<<"is : ";pv(is,is+3);
            for (j = 0; j < 3; ++j) {
                i = is[j];
                for (uint l = 0; l < residents[i].size(); ++l) {
                    k = residents[i][l];
                    used[k] = j;
                }
            }
            makeAnswer(is);
            return;
        }
    }
}

int main() {
    int i, j, k;
    char buf[110];
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            scanf("%s", buf); nameI[i] = buf;
            scanf("%s", buf); clasI[i] = buf;
            for (j = 0; j < 3; ++j) {
                P[i][j] = in();
            }
            sz[i] = in();
        }
        K = in();
        for (k = 0; k < K; ++k) {
            scanf("%s", buf); nameR[k] = buf;
            scanf("%s", buf); typeR[k] = buf;
            bonus[k] = in();
            scanf("%s", buf); home[k] = buf;
        }
        
        memset(used, ~0, sizeof(used));
        
        map<string,int> trNameI;
        residents = vector<vint>(N, vint());
        for (i = 0; i < N; ++i) {
            trNameI[nameI[i]] = i;
        }
        for (k = 0; k < K; ++k) {
            i = trNameI[home[k]];
            residents[i].push_back(k);
        }
        
        for (i = 0; i < N; ++i) {
            clas[i] = -1;
            if (clasI[i][0] == 'w') clas[i] = 0;
            if (clasI[i][0] == 'a') clas[i] = 1;
            if (clasI[i][0] == 'o') clas[i] = 2;
        }
        for (k = 0; k < K; ++k) {
            type[k] = -1;
            if (typeR[k][0] == 'g') type[k] = 0;
            if (typeR[k][0] == 's') type[k] = 1;
            if (typeR[k][0] == 'p') type[k] = 2;
        }
        
        //  no move
        if (accumulate(sz, sz + N, 0) == K) {
            solveSpecial();
            continue;
        }
        
        dping();
        takeMax();
        
    }
    
    return 0;
}