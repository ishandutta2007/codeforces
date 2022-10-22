#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll s[3][25];

ll res;

int a[2000005];
int niz[2000005];
int novi[2000005];

ll merge(int l1, int r1, int l2, int r2){
    int j = l2-1;
    ll cnt = 0;
    int tren = l1-1;
    for(int i=l1; i<=r1; i++){
        while(j < r2 && a[j+1] < a[i]){
            novi[++tren] = a[j+1];
            j++;
        }
        cnt += j-(l2-1);
        novi[++tren] = a[i];
    }
    while(j < r2){
        novi[++tren] = a[j+1];
        j++;
    }
    for(int i=l1; i<=r2; i++) a[i] = novi[i];
    return cnt;
}

void init(int l, int r, int h, int koji){
    if(l == r) return;
    int mid = (l+r)/2;
    init(l, mid, h+1, koji);
    init(mid+1, r, h+1, koji);
    ll x = merge(l, mid, mid+1, r);
    s[koji][h] += x;
    if(koji == 1) res += x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=(1<<n); i++){
        cin >> niz[i];
        a[i] = niz[i];
    }
    init(1, (1<<n), 0, 1);
    reverse(niz+1, niz+1+(1<<n));
    for(int i=1; i<=(1<<n); i++){
        a[i] = niz[i];
    }
    init(1, (1<<n), 0, 2);
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        x = n-x;
        while(x <= n){
            res -= s[1][x];
            res += s[2][x];
            swap(s[1][x], s[2][x]);
            x++;
        }
        cout << res << "\n";
    }
    return 0;
}