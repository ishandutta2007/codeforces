#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll niz[1000000];
ll kum[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, s, f;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    cin >> s >> f;
    ll s1, f1;
    for(int i=1; i<=n; i++){
        s1 = s-i+1;
        if(s1 <= 0) s1 += n;
        f1 = f-i+1;;
        if(f1 <= 0) f1 += n;
        if(s1 > f1){
            kum[1] += niz[i];
            kum[f1] -= niz[i];
            kum[s1] += niz[i];
        }
        else {kum[s1] += niz[i]; kum[f1] -= niz[i];}
    }
    kum[0] = 0;
    ll maxi = 0;
    for(int i=1; i<=n; i++){
        kum[i] = kum[i]+kum[i-1];
        maxi = max(maxi, kum[i]);
    }
    for(int i=1; i<=n; i++){
        if(kum[i] == maxi){cout << i; return 0;}
    }
    return 0;
}