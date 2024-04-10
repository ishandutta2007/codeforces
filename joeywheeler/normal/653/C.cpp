#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int t[150005];
vector<int> bd;

bool chk(int i) {
    if (i < 0 || i >= n-1) return true;
    if (i%2 == 0 && t[i] >= t[i+1]) return false;
    if (i%2 == 1 && t[i] <= t[i+1]) return false;
    return true;
}

bool fx(int i, int j) {
    swap(t[i], t[j]);
    bool gd = true;
    for (int i : bd) {
        if (!chk(i)) gd = false;
    }
    if (!chk(i-1)) gd = false;
    if (!chk(i)) gd = false;
    if (!chk(j-1)) gd = false;
    if (!chk(j)) gd = false;
    swap(t[i], t[j]);
    return gd;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", &t[i]);
    int j = -1;
    FO(i,0,n-1) {
        if (!chk(i)) {
            //printf("i=%d\n",i);
            bd.push_back(i);
            j = i;
        }
    }
    if (sz(bd) > 5) {
        printf("0\n");
        return 0;
    }
    int res = 0;
    FO(i,0,n) if (fx(j,i)) res++;
    FO(i,0,n) if (fx(j+1,i)) res++;
    if (fx(j,j+1)) res--;
    printf("%d\n", res);
}