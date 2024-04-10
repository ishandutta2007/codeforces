#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct nesto{
    ll x;
    ll br2;
    ll br3;
} niz[1000];

bool cmp1(nesto a, nesto b){
    return a.br2 < b.br2;
}

bool cmp2(nesto a, nesto b){
    return a.br3 > b.br3;
}

nesto niz1[1000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    ll n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i].x;
        ll x = niz[i].x;
        while(x%2 == 0){
            x /= 2;
            niz[i].br2++;
        }
        while(x%3 == 0){
            x /= 3;
            niz[i].br3++;
        }
    }
    sort(niz+1, niz+n+1, cmp1);
    int l = 1;
    int r = 1;
    while(r <= n){
        while(r <= n && niz[l].br2 == niz[r].br2) r++;
        if(r > n) r--;
        else if(niz[r].br2 != niz[l].br2) r--;
        for(int i=l; i<=r; i++){
            niz1[i-l+1].x = niz[i].x;
            niz1[i-l+1].br2 = niz[i].br2;
            niz1[i-l+1].br3 = niz[i].br3;

        }
        sort(niz1+1, niz1+1+r-l+1, cmp2);
        for(int i=l; i<=r; i++){
            cout << niz1[i-l+1].x << " ";
        }
        l = r+1;
        r = l;
    }
    return 0;
}