#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int h[MAXN];
const long long LLMAX = 999999999999999999ll;
long long dpl[MAXN], dpr[MAXN];
int ehl[MAXN], ehr[MAXN];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
    dpl[1] = 0;
    int ph = h[1];
    for(int i = 2; i <= n; i++){
        int exph = max(ph + 1, h[i]);
        dpl[i] = dpl[i - 1] + exph - h[i];
        ehl[i] = exph;
        ph = exph;
    }
    int rh = h[n];
    for(int i = n - 1; i >= 1; i--){
        int exph = max(rh + 1, h[i]);
        dpr[i] = dpr[i + 1] + exph - h[i];
        ehr[i] = exph;
        rh = exph;
    }
    long long ans = LLMAX;
    for(int peak = 1; peak <= n; peak++){
        //cout << dpl[peak] << " " << dpr[peak] << endl;
        long long cur_ans = dpl[peak - 1] + dpr[peak + 1];
        int toreach = max(ehl[peak - 1] + 1, ehr[peak + 1] + 1);
        cur_ans += max(0, toreach - h[peak]);
        ans = min(ans, cur_ans);
    }
    cout << ans << endl;
    return 0;
}