#include <bits/stdc++.h>
using namespace std;

int niz[100];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> niz[i];
    }
    while(n){
        int maxnum = 0;
        for(int i=1; i<n; i++){
            if(niz[i]-1 > niz[i-1]){cout << "NO"; return 0;}
        }
        for(int i=0; i<n-1; i++){
            if(niz[i]-1 > niz[i+1]){cout << "NO"; return 0;}
        }
        for(int i=0; i<n; i++){
            maxnum = max(maxnum, niz[i]);
        }
        int ind = 0;
        for(int i=0; i<n; i++){
            if(maxnum == niz[i]){ind = i; break;}
        }
        n--;
        for(int i=ind; i<n; i++) niz[i] = niz[i+1];
    }
    cout << "YES";
    return 0;
}