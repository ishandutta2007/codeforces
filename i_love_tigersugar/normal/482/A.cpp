#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int main(void) {
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> perm;
    int l=n-k;
    int r=n;
    REP(i,k+1) {
        if (i%2==0) {
            perm.push_back(l);
            l++;
        } else {
            perm.push_back(r);
            r--;
        }
    }
    FOR(i,1,n-k-1) printf("%d ",i);
    REP(i,k+1) printf("%d ",perm[i]);
    return 0;
}