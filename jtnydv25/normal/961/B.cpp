
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
const int N = 100005;
int a[N], t[N];
int pref1[N], pref2[N];
int main(){
    int k, n;
    sd(n); sd(k);
    for(int i = 1; i <= n; i++) sd(a[i]), pref1[i] = pref1[i - 1] + a[i];
    for(int i = 1; i <= n; i++) sd(t[i]), pref2[i] = pref2[i - 1] + a[i] * t[i];
    int ans = pref2[n];
    int x = ans;
    for(int i = 1; i + k - 1<= n; i++){
        ans = max(ans, x + pref1[i + k - 1] - pref1[i - 1] - pref2[i + k - 1] + pref2[i - 1]);
    }
    printf("%d\n", ans);
}