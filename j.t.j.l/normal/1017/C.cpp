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

int LIS(int n, const vector<int> &a){
    vector<int> c(n);
    c[0] = 1;
    int ans = 1;
    for (int i = 1; i < n; i++){
        c[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[j] < a[i] && c[j] + 1 > c[i])
                c[i] = c[j] + 1;
        ans = max(ans, c[i]);
    }
    return ans;
}

void gao(int n){
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        b[i] = i + 1;
    a = b;
    int ans = n + 1;
    int cnt = 0;
    do{
        int now = LIS(n, b);
        reverse(b.begin(), b.end());
        now += LIS(n, b);
        reverse(b.begin(), b.end());
        if (now < ans){
            ans = now;
            a = b;
        }
        cnt++;
    }while(next_permutation(b.begin(), b.end()));
    cout << " ============ " << endl;
    cout << n << ' ' << cnt << ' ' << ans << endl;
    for (auto &x : a)
        cout << x << ' '; cout << endl;
}

int main(){
    //for (int i = 2; i <= 10; i++)
    //    gao(i);
    int n;
    scanf("%d", &n);
    if (n == 1){
        puts("1");
        return 0;
    }
    int p = 1, q = 1;
    while (true){
        q++;
        if (p * q >= n)
            break;
        p++;
        if (p * q >= n)
            break;
    }
    assert(p * q >= n);
    // 3 2 1 6 5 4
    int cnt = 0;
    for (int i = 1; i <= p; i++){
        for (int j = q; j >= 1; j--){
            int x = (i - 1) * q + j;
            if (x <= n)
                printf("%d%c", x, " \n"[++cnt == n]);
        }
    }
    return 0;
}