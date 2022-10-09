#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> beacon;

int D[100005], N;
beacon A[100005];

int untouched(int x){ // x je najmanja unistena koordinata
    int l=1, r=N, o=0, m;
    while (l<=r){
        m = (l+r)/2;
        if (A[m].first < x){
            o = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }
    return o;
}

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++){
        scanf("%d%d", &A[i].first, &A[i].second);
    }
    sort(A+1, A+N+1);
    int m = 0;
    for (int i=1; i<=N; i++){
        D[i] = 1 + D[untouched(A[i].first - A[i].second)];
        m = max(m, D[i]);
    }
    printf("%d\n", N-m);
    return 0;
}