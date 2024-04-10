#include <bits/stdc++.h>
using namespace std;

int pr[100005];
int pre1[100005];
int pre2[100005];
int res[100005];
bool gud[100005];

const int MOD = 1000000007;

int main(){

    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int x=1, l=0;
    while(x < m){
        if(t[x] == t[l]){
            l++;
            pr[x] = l;
            x++;
        }
        else if(l == 0){
            pr[x] = 0;
            x++;
        }
        else l = pr[l-1];
    }
    int y = 0;
    x = 0;
    while(x < n){
        if(s[x] == t[y]){
            x++;
            y++;
        }
        if(y == m){
            gud[x] = 1;
            y = pr[y-1];
        }
        else{
            if(x >= n || s[x] == t[y]) continue;
            if(y) y = pr[y-1];
            else x++;
        }
    }
    int sum = 0;
    for(int i=1; i<=n; i++){
        if(gud[i]) res[i] = (pre2[i-m]+(i-m+1))%MOD;
        else res[i] = res[i-1];
        pre1[i] = (pre1[i-1]+res[i])%MOD;
        pre2[i] = (pre2[i-1]+pre1[i])%MOD;
        sum = (sum+res[i])%MOD;
    }
    cout << sum;
    return 0;
}