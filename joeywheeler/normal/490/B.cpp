#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int nxt[1000005];
int prev[1000005];
bool used[1000005];
int ment[1000005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int a, b; scanf("%d %d", &a, &b); nxt[a] = b;
        ment[a]++; ment[b]--;
    }
    vector<int> seq0,seq1;
    int i = nxt[0];
    while (i != 0) {
        seq0.push_back(i);
        ment[i]-=2;
        i = nxt[i];
    }
    FO(j,1,1000005) {
        if (ment[j] == 1) {
            i = j;
        }
    }
    while (i != 0) {
        seq1.push_back(i);
        i = nxt[i];
    }
    int a=0,b=0;
    while (a < sz(seq0) || b < sz(seq1)) {
        if (a < b) printf("%d ", seq0[a++]);
        else printf("%d ", seq1[b++]);
    }
    printf("\n");
}