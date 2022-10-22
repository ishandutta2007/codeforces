#include <bits/stdc++.h>
using namespace std;

int niz[1000000];
int zl[1000000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> niz[i];
    string str;
    cin >> str;
    zl[1] = str[0]-'0';
    for(int i=2; i<=n-1; i++)zl[i] = zl[i-1]+(str[i-1]-'0');
    for(int i=1; i<=n; i++){
        if(niz[i]>i){
            if(zl[niz[i]-1]-zl[i-1] != niz[i]-i){cout << "NO"; return 0;}
        }
    }
    cout << "YES";
    return 0;
}