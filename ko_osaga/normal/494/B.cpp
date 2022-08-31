#include <cstdio>
const long long mod = 1e9 + 7;

char s[100005], t[100005];
bool match[100005];
int hash = 37, len, len2;
long long thash, shash, pivot = 1;

long long dp[100005][2][2];
int latest_match[100005];

void solve(){
    dp[len2][1][0] = dp[len2][1][1] = 1;
    for (int i=len2-1; i>=0; i--) {
        dp[i][0][0] = dp[i+1][0][0] + (dp[i+1][0][0] - dp[i+2][0][0]) + (dp[i+1][0][1] - dp[i+2][0][1]);
        dp[i][1][0] = dp[i+1][1][0] + (dp[i+1][1][0] - dp[i+2][1][0]) + (dp[i+1][1][1] - dp[i+2][1][1]);
        dp[i][0][0] %= mod;
        dp[i][1][0] %= mod;
        int j = latest_match[i];
        if(latest_match[i] > len2){
            dp[i][0][1] = dp[i+1][0][1];
            dp[i][1][1] = dp[i+1][1][1];
            continue;
        }
        dp[i][0][1] = dp[i+1][0][1] + dp[j+len][1][0] + dp[j+len][1][1];
        dp[i][1][1] = dp[i+1][1][1] + dp[j+len][1][0] + dp[j+len][1][1];
        dp[i][0][1] %= mod;
        dp[i][1][1] %= mod;
    }
}

int main(){
    scanf("%s %s",s,t);
    for (int i=0; t[i]; i++) {
        pivot *= 37;
        thash = thash * 37 + (t[i] - 'a');
        len++;
    }
    for (int i=0; s[i]; i++) {
        len2++;
        shash = shash * 37 + (s[i] - 'a');
        if(i >= len) shash -= pivot * (s[i-len] - 'a');
        if(i >= len-1 && shash == thash) match[i-len+1] = 1;
    }
    latest_match[len2] = len2+1;
    for (int i=len2-1; i>=0; i--) {
        if(match[i]) latest_match[i] = i;
        else latest_match[i] = latest_match[i+1];
    }
    solve();
    long long r = dp[0][0][0] + dp[0][0][1] - dp[1][0][0] - dp[1][0][1];
    r %= mod;
    if(r < 0) r += mod;
    if(r & 1) r += mod;
    r /= 2;
    printf("%I64d",r);
}