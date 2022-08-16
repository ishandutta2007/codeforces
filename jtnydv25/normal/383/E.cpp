#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define sd(x) scanf("%d", &(x))

const int M = 24;
const int TOTAL = (1 << 24) - 1;
int A[TOTAL + 1], F[TOTAL + 1];
char s[3];
int main(){
    int n;
    sd(n);
    for(int i = 1; i <= n; i++){
        scanf("%s", s);
        int msk = 0;
        for(int j = 0; j < 3; j++) msk |= (1 << (s[j] - 'a'));
        A[msk]++;
    }

    for(int i = 0; i<(1<<24); ++i) F[i] = A[i];
    for(int i = 0;i < M; ++i) for(int mask = 0; mask < (1<<M); ++mask){
        if(mask & (1<<i))
            F[mask] += F[mask^(1<<i)];
    }
    long long ans = 0;
    for(int i = 0; i < (1 << 24); i++){
        long long y = (n - F[i]) * 1ll * (n - F[i]);
        ans ^= y;
    }
    cout << ans;
}