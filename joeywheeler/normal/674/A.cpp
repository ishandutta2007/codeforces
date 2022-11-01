#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int t[5005];
int fq[5005]; // freq of this ball
int mxf, mni;
int res[5005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%d", t+i); t[i]--;
    }
    FO(i,0,n) {
        FO(j,0,n+1) fq[j] = 0;
        mxf = 0, mni = 0;
        FO(j,i,n) {
            fq[t[j]]++;
            if (fq[t[j]] > mxf || (fq[t[j]] == mxf && t[j] < mni)) {
                mxf = fq[t[j]];
                mni = t[j];
            }
            res[mni]++;
        }
    }
    FO(i,0,n) printf("%d ", res[i]);
    printf("\n");
}