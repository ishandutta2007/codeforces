#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5 + 4;
char A[NS], B[NS];
int AN, BN;
vector < int > vc;

int main(){
    scanf("%s %s", A + 1, B + 1);
    AN = strlen(A + 1), BN = strlen(B + 1);
    int l, lp, r, rp;
    l = 0, r = BN, lp = 0, rp = AN + 1;
    vc.push_back(0);
    while(l < BN){
        ++lp;
        if(A[lp] == B[l + 1]) ++l, vc.push_back(lp);
    }
    int ans = rp - lp - 1;
    while(l){
        vc.pop_back(), lp = vc.back();
        --l;
        while(A[rp - 1] != B[r]) --rp;
        --rp; --r;
        ans = max(ans, rp - lp - 1);
    }
    printf("%d\n", ans);
    return 0;
}