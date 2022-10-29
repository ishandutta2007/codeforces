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

int a[MAXN];
ll b[MAXN];
int debug = 1;
int m;

ll gao(int n, ll d, ll t){
    ll ret = 0, now = 0, cnt = 0, ans = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] <= d){
            if (cnt == m){
                ret += now;
                now = cnt = 0;
            }
            if (ret + a[i] > t)
                break;
            ret += a[i];
            now += a[i];
            cnt++;
            ans++;
        }
    return ans;
}

void solve(int casi){
    //printf("Case #%d:", casi);
    int n;
    ll t;
    scanf("%d%d%lld", &n, &m, &t);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), b[i] = a[i];
    sort(b + 1, b + n + 1);
    int mm = unique(b + 1, b + n + 1) - b - 1;
    while (b[mm] > t) mm--;
    //cout << mm << endl;
    int l = 1, r = mm + 1;
    b[mm + 1] = min(t, b[mm] + 1);
    b[mm + 2] = min(t, b[mm] + 2);
    while (l + 1 < r){
        int mid = (l + r) / 2;
        ll ret = 0, now = 0, cnt = 0;
        for (int i = 1; i <= n; i++){
            if (a[i] <= b[mid]) {
                if (cnt == m){
                    ret += now;
                    now = cnt = 0;
                }
                now += a[i];
                cnt++;
                ret += a[i];
            }
        }
        if (ret <= t)
            l = mid;
        else
            r = mid;
    }
    //cout << b[0] << ' ' << b[1] << ' ' << b[2] << ' ' << b[3] << endl;
    //cout << l << ' ' << b[l] << endl;
    int mid = l;
    ll ret = 0, now = 0, cnt = 0, ans1 = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] <= b[mid]) {
            if (cnt == m){
                ret += now;
                now = cnt = 0;
            }
            if (ret + a[i] > t)
                break;
            now += a[i];
            cnt++;
            ret += a[i];
            ans1++;
        }
    }
    mid = l + 1;
    ret = 0, now = 0, cnt = 0;
    ll ans2 = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] <= b[mid]) {
            if (cnt == m){
                ret += now;
                now = cnt = 0;
            }
            if (ret + a[i] > t)
                break;
            now += a[i];
            cnt++;
            ret += a[i];
            ans2++;
        }
    }
    mid--;
    if (ans2 > ans1){
        ans1 = ans2;
        mid = mid + 1;
    }
    if (b[mid] == 0)
        b[mid]++;
    printf("%lld %lld\n", ans1, b[mid]); 
    /*if (debug) {
        assert(gao(n, b[mid], t) == ans1);
        for (int i = 1; i <= 100; i++)
            assert(gao(n, i, t) <= ans1);
    }*/
}  

int main(){
    int T = 1;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}