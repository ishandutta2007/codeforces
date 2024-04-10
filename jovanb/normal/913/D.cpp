#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int n, t;

struct strukt{
    int lm;
    int val;
    int ind;

} niz[500005];

bool checc(int k){
    int br=0;
    int sum=0;
    for(int i=1; i<=n; i++){
        if(niz[i].lm >= k && br < k){
            br++;
            sum += niz[i].val;
        }
    }
    return br >= k && sum <= t;
}

bool cmp(strukt a, strukt b){
    return a.val < b.val;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n >> t;
    for(int i=1; i<=n; i++){
        cin >> niz[i].lm >> niz[i].val;
        niz[i].ind = i;
    }
    sort(niz+1, niz+1+n, cmp);
    int l=1, r=n, mx=0;
    while(l <= r){
        int mid = (l+r)/2;
        if(checc(mid)){l = mid+1; mx = mid;}
        else r = mid-1;
    }
    cout << mx << "\n" << mx << "\n";
    int br=0;
    for(int i=1; i<=n; i++){
        if(niz[i].lm >= mx && br < mx){
            br++;
            cout << niz[i].ind << " ";
        }
    }
    return 0;
}