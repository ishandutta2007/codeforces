#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int n, ans;
int a[1111];

void gao(int l, int r) {
    //cout << l << ' ' << r << endl;
    int flag = 1;
    for (int i = l + 1; i <= r; i++)
        if (a[i] < a[i - 1]) {
            flag = 0;
            break;
        }
    if (flag == 1) {
        ans = max(ans, r - l + 1);
        return ;
    }
    int m = (r - l + 1) / 2 + l;
    gao(l, m - 1);
    gao(m, r);
}

void solve(int casi){
    //printf("Case #%d:", casi);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    ans = 1;
    gao(1, n);
    cout << ans << endl;
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}