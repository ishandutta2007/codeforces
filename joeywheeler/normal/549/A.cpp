#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int h, w; char g[55][55];

int main() {
    scanf("%d%d", &h, &w);
    FO(y,0,h) scanf(" %s", g[y]);
    int res = 0;
    FO(y,0,h-1) FO(x,0,w-1) {
        string s = "";
        FO(i,0,2) FO(j,0,2) s += g[y+i][x+j];
        sort(s.begin(),s.end());
        if (s == "acef") res++;
    }
    printf("%d\n", res);
}