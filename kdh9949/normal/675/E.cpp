#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

struct MaxPosSeg{
    int data[1048577];
    int from[1048577];
    int sz;
    MaxPosSeg(int n, int *a){
        for(sz = 1; sz < n; sz *= 2);
        for(int i = sz; i < sz + n; i++){
            data[i] = a[i - sz + 1];
            from[i] = i - sz + 1;
        }
        for(int i = sz - 1; i >= 1; i--){
            int wh = (data[2 * i] > data[2 * i + 1]) ?
                     (2 * i) : (2 * i + 1);
            data[i] = data[wh];
            from[i] = from[wh];
        }
    }
    int getpos(int s, int e){
        s += sz - 1; e += sz - 1;
        int mval = 0, mpos = -1;
        while(s <= e){
            if(s % 2 == 1){
                if(mval < data[s]){ mval = data[s]; mpos = from[s]; }
                s++;
            }
            if(e % 2 == 0){
                if(mval < data[e]){ mval = data[e]; mpos = from[e]; }
                e--;
            }
            s /= 2; e /= 2;
        }
        return mpos;
    }
} *MPS;

int N;
int A[300001];
int p[300001];
ll dp[300001];
bool chk[300001];

void pre_process(){
    MPS = new MaxPosSeg(N, A);
    for(int i = 1; i < N; i++) p[i] = MPS->getpos(i + 1, A[i]);
}

ll f(int x){
    if(x == N) return 0;
    if(chk[x]) return dp[x];
    dp[x] = f(p[x]) + (N - x) - (A[x] - p[x]);
    chk[x] = true;
    return dp[x];
}

int main(){
    scanf("%d", &N);
    for(int i = 1; i < N; i++) scanf("%d", A + i);
    A[N] = N;
    pre_process();
    ll ans = 0;
    for(int i = 1; i < N; i++) ans += f(i);
    printf("%lld\n", ans);
}