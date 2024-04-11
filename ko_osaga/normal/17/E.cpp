#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;
const int mod = 51123987;

int n;
char str[2000005];
char str2[4000005];
int dp[4000005];

int left[4000005], right[4000005];

void input(){
    scanf("%d %s",&n,str);
    str2[0] = '$';
    for (int i=0; str[i]; i++) {
        str2[2*i+1] = str[i];
        str2[2*i+2] = '$';
    }
    n = 2*n+1;
    int cent = 0, high = 0;
    for (int i=0; i<n; i++) {
        if(high >= i){
            dp[i] = min(high - i, dp[2*cent-i]);
        }
        while (i + dp[i] + 1 < n && i - dp[i] - 1 >= 0 && str2[i+dp[i]+1] == str2[i-dp[i]-1]) {
            dp[i]++;
        }
        if(high <= dp[i] + i){
            high = dp[i] + i;
            cent = i;
        }
    }
    for (int i=1; i<n-1; i++) {
        if(i % 2 == 1){
            left[(i+1)/2 - dp[i]/2] ++;
            left[(i+1)/2 + 1]--;
        }
        if(i % 2 == 0){
            left[i / 2 + 1 - dp[i] / 2]++;
            left[i/2 + 1]--;
        }
    }
    for (int i=1; i<=n/2; i++) {
        left[i] += left[i-1];
        left[i] %= mod;
    }
    for (int i=1; i<=n/2; i++) {
        left[i] += left[i-1];
        left[i] %= mod;
    }
}

int sum(int x){
    return (1ll * x * (x+1) / 2) % mod;
}

int main(){
    input();
    int ret = 0;
    for (int i=1; i<=n/2; i++) {
        int cnt = left[i] - left[i-1] + mod;
        ret += (1ll * cnt * (cnt-1) / 2) % mod;
        ret %= mod;
    }
    for (int i=1; i<=n/2; i++) {
        left[i] += left[i-1];
        left[i] %= mod;
    }
    for (int i=1; i<=n-1; i++){
        if(i % 2 == 1){
            ret += left[(i+1)/2 + dp[i]/2] - left[(i+1)/2 - 1] + mod;
            ret -= left[(i+1)/2] - left[(i+1)/2 - dp[i]/2 - 1] - mod;
            ret %= mod;
        }
        else{
            ret += left[i/2 + dp[i]/2] - left[i/2] + mod;
            ret -= left[i/2] - left[i/2 - dp[i]/2] - mod;
            ret %= mod;
        }
    }
    printf("%d",ret);
}