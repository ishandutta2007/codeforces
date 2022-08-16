#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int A[N], B[N], perm[N], perm2[N], A2[N];
bool cmp(int i, int j){ return B[i] < B[j];}
bool cmp2(int i, int j){ return A[i] > A[j];}
int main(){
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]), perm2[i] = i;
    for(int i = 1; i <= n; i++) scanf("%d", &B[i]), perm[i] = i;
    sort(perm + 1, perm + n + 1, cmp);
    sort(perm2 + 1, perm2 + n + 1, cmp2);
    for(int i = 1; i <= n; i++){
        A2[perm[i]] = A[perm2[i]];
    }
    for(int i = 1; i <= n; i++) printf("%d ", A2[i]);
}