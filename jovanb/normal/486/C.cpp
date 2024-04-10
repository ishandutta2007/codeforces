#include <bits/stdc++.h>
using namespace std;

long niz[100005];
long pom[100005];
char ch[100005];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0);
    cout.precision(10);
    cout<<fixed;

    long n, i, m, ind2=0, cost = 0, ind1=-1;
    cin >> n >> m;
    cin >> ch;
    for(i=n; i>=1; i--)niz[i] = ch[i-1];
    if(m > n/2){
        for(i=1; i<=n; i++){
            pom[i] = niz[n-i+1];
        }
        for(i=1; i<=n; i++){
            niz[i] = pom[i];
        }
        m = n-m+1;
    }
    for(i=1; i<=n/2; i++){
        if(niz[i] != niz[n-i+1]){
            ind2 = i;
            if(ind1 == -1) ind1 = i;
        }
    }
    for(i=ind1; i<=ind2; i++){
        cost += min(abs(niz[i]-niz[n-i+1]), 26-abs(niz[i]-niz[n-i+1]));
    }
    if(ind1 == -1)cout << 0;
    else cout << cost+abs(ind2-ind1)+min(abs(ind2-m),abs(ind1-m));
    return 0;
}