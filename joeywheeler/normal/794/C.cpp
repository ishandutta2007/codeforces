#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

string v0, v1;
int n;
char ans[300005];

int wholst(int npl, int rpl) {
    if ((npl+rpl)%2 == 1) return 0;
    else return 1;
}

int whonek(int npl) {
    if (npl%2 == 0) return 0;
    else return 1;
}

int main() {
    cin >> v0 >> v1;
    n = v0.size();
    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end());

    v0 = v0.substr(0, (n+1)/2);
    v1 = v1.substr((n+1)/2);
    int npl = 0;
    int fi0 = 0;
    int bi1 = sz(v1)-1;
    while (npl < n-1) {
        int w = whonek(npl);
        if (v0[fi0] >= v1[bi1]) goto nkstg;
        if (w == 0) {
            ans[npl++] = v0[fi0++];
        } else {
            ans[npl++] = v1[bi1--];
        }
    }
    nkstg:;
    int rpl = n - npl;
    int ri = npl;
    while (rpl > 0) {
        int w = wholst(npl, rpl);
        if (w == 0) {
            ans[ri++] = v0[fi0++];
        } else {
            ans[ri++] = v1[bi1--];
        }
        rpl--;
    }
    printf("%s\n", ans);
}