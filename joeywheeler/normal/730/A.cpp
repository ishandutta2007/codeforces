#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int N, r[105];

void trydo (int c) {
    int diffam[105];
    int totSum(0), maxsum(0);
    FO (i,0,N) {
        if (r[i] < c) return;
        diffam[i] = r[i]-c;
        totSum += diffam[i];
        maxsum = max (maxsum, diffam[i]);
    }
    if (maxsum > totSum-maxsum && c != 0) return;
    vector <string> allAns;
    while (true) {
        pii cDiff[105];
        FO (i,0,N) {
            cDiff[i] = {diffam[i], i};
        }
        sort (cDiff, cDiff+N);
        reverse (cDiff,cDiff+N);
        if (cDiff[0].first == 0) break;
        if (cDiff[1].first == 0 && c != 0) return;
        if (cDiff[3].first == 0 && cDiff[0].first == 1 && cDiff[2].first == 1) {
            string cStr = "";
            FO (i,0,N) {
                if (i == cDiff[0].second || i == cDiff[1].second || i == cDiff[2].second) {
                    diffam[i]--;
                    diffam[i] = max (diffam[i], 0);
                    cStr += '1';
                } else {
                    cStr += '0';
                }
            }
            allAns.push_back (cStr);
        } else {
            string cStr = "";
            FO (i,0,N) {
                if (i == cDiff[0].second || i == cDiff[1].second) {
                    diffam[i]--;
                    diffam[i] = max (diffam[i], 0);
                    cStr += '1';
                } else {
                    cStr += '0';
                }
            }
            allAns.push_back (cStr);
        }
    }
    printf ("%d\n", c);
    printf ("%d\n", allAns.size());
    FO (i,0,allAns.size()) {
        printf ("%s\n", allAns[i].c_str());
    }
    exit (0);
}


int main() {
    scanf ("%d", &N);
    FO (i,0,N) scanf ("%d", &r[i]);
    for (int i = 100; i >= 0; i--) {
        trydo(i);
    }



    return 0;
}