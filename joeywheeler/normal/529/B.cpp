#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
pair<int,int> v[1005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int w,h; scanf("%d%d", &w, &h);
        v[i] = {w,h};
    }
    sort(v, v+n, [](pair<int,int> &a, pair<int,int> &b) {return a.second-a.first < b.second-b.first;});
    int res = 2e9;
    FO(H,1,1001) {
        int W = 0, nh = n/2;
        vector<int> e;
        FO(i,0,n) {
            int w, h; tie(w,h) = v[i];
            if (w > H && h > H) nh = -1;
            if (w > H) {
                W += w;
            } else if (h > H) {
                W += h; nh--;
            } else {
                W += w; e.push_back(h-w);
            }
        }
        if (nh >= 0) {
            FO(i,0,min(nh,sz(e))) W += min(e[i],0);
            res = min(res, W*H);
        }
    }
    printf("%d\n", res);
}