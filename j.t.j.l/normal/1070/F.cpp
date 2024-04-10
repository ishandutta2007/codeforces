#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;


ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

vector<int> f[10];
char s[10];

void solve(int casi){
    //printf("Case #%d:", casi);
    int n;
    scanf("%d", &n);
    ll ans = 0;
    int sm = 0, c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++){
        int x, y;
        scanf("%s%d", s, &x);
        y = (s[0] - '0') * 2 + s[1] - '0';
        if (y == 3){
            ans += x;
            c1++,c2++,sm++;
        }
        else
            f[y].push_back(x);
    }
    for (int i = 0; i <= 2; i++){
        sort(f[i].begin(), f[i].end());
        //reverse(f[i].begin(), f[i].end());
    }
    while (f[1].size() && f[2].size()){
        ans += f[1].back() + f[2].back();
        f[1].pop_back();
        f[2].pop_back();
        c1++,c2++;sm+=2;
    }
    for (auto &x : f[1]) f[0].push_back(x);
    for (auto &x : f[2]) f[0].push_back(x);
    sort(f[0].begin(), f[0].end());
    reverse(f[0].begin(), f[0].end());
    for (auto &x : f[0]){
        if (c1 * 2 >= sm + 1){
            ans += x;
            sm++;
        }
    }
    printf("%lld\n", ans);
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}