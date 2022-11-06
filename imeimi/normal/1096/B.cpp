#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;
const int mod = 998244353;
char str[200001];
int n;
int mx[256], mn[256];
int main(){
scanf("%d%s", &n, str);
for (int i = 0; i < 256; ++i) mx[i] = -1, mn[i] = n;
for (int i = 0; i < n; ++i){
for (char j = 'a'; j <= 'z'; ++j){
if (str[i] == j) continue;
mn[j] = min(mn[j], i);
mx[j] = max(mx[j], i);
}
}
long long ans=1;
for (char i= 'a'; i<='z';++i){
if (mx[i] ==-1) ans += (long long)n * (n + 1) / 2 - 1;
else ans += (long long)(mn[i] + 1)*(n-mx[i])-1;
}
printf("%lld", ans % mod);
}