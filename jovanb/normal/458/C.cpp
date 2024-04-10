#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair <int, int> niz[100005];
int br[100005];
int brr[100005];
int n, m=100000;
bool used[100005];

ll resi(int x){
    ll sum = 0;
    for(int i=0; i<=m; i++) brr[i] = br[i];
    for(int i=1; i<=n; i++) used[i] = 0;
    int k = br[0];
    for(int i=1; i<=n; i++){
        int j = niz[i].second;
        int val = niz[i].first;
        if(j == 0) continue;
        if(brr[j] >= x){
            brr[j]--;
            k++;
            sum += val;
            used[i] = 1;
        }
    }
    for(int i=1; i<=n; i++){
        int j = niz[i].second;
        int val = niz[i].first;
        if(j == 0) continue;
        if(k < x && !used[i]){
            used[i] = 1;
            k++;
            sum += val;
        }
    }
    return sum;
}

ll ternary(int l, int r){
    while(l <= r){
        if(l == r) return resi(l);
        int a = (2*l+r)/3;
        int b = (2*r+l+1)/3;
        ll a1 = resi(a);
        ll b1 = resi(b);
        if(a1 > b1) l = a+1;
        else r = b-1;
    }
    return resi(l-1);
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i].second >> niz[i].first;
        br[niz[i].second]++;
    }
    sort(niz+1, niz+1+n);
    cout << ternary(1, n) << "\n";
    return 0;
}