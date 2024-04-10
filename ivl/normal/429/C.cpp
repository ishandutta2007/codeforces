#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector < int > v;
int nn;
int lc;

bool dp(int lc, int pos, int cnt, int bit){
     if (pos == nn){
        if (pos == 0) return true;
        if (lc) return false;
        if (__builtin_popcount(bit) != nn - 1) return false;
        return true;
     }
     static bool bio[25][12][24][1 << 12];
     static int memo[25][12][24][1 << 12];
     int &r = memo[lc][pos][cnt][bit];
     if (bio[lc][pos][cnt][bit]++) return r;
     if (cnt == 1) return r = dp(lc, pos + 1, v[pos + 1], bit);
     for (int i = 0; v[i] < v[pos] - 1; ++i){
         if ((bit & (1 << i)) == 0){
            if (v[i] >= cnt) continue;
            r |= dp(lc, pos, cnt - v[i], bit | (1 << i));
         }
     }
     if (lc) r |= dp(lc - 1, pos, cnt - 1, bit);
     
     return r;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        int a;
        scanf("%d", &a);
        if (a == 2){printf("NO\n"); return 0;}
        if (a == 1) ++lc;
        else v.push_back(a);
    }
    sort(v.begin(), v.end());
    nn = v.size();
    v.push_back(1000);
    if (dp(lc, 0, v[0], 0)) printf("YES\n");
    else printf("NO\n");
    return 0;
}