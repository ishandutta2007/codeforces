#include <bits/stdc++.h>
using namespace std;

int niz[1000005];
bool ima[1000005];

int main(){
    ios_base::sync_with_stdio(false);

    int n, s;
    cin >> n >> s;
    int res = 0;
    int mx = 0;
    ima[0] = 1;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        if(i == s && niz[i]){
            niz[i] = 0;
            res++;
        }
    }
    for(int i=1; i<=n; i++){
        if(niz[i] == 0 && i != s){
            niz[i] = n+2;
        }
        ima[niz[i]] = 1;
    }
    sort(niz+1, niz+1+n);
    while(1){
        mx++;
        if(niz[n] <= mx) break;
        else{
            if(!ima[mx]){
                res++;
                n--;
            }
        }
    }
    cout << res;
    return 0;
}