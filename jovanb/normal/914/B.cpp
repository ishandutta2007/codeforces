#include <bits/stdc++.h>
using namespace std;

long long niz[200000];
unordered_map <long, long> br;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    long n, dosad=0, i, x, pravon=0;
    cin >> n;
    for(i=0; i<n; i++){
        cin >> x;
        if(br[x] == 0)niz[pravon++] = x;
        br[x]++;
    }
    n = pravon;
    sort(niz,niz+n);
    for(i=n-1; i>=0; i--){
        if((dosad+br[niz[i]])%2 != 0) {cout << "Conan"; return 0;}
        else dosad += br[niz[i]];
    }
    cout << "Agasa";
    return 0;
}