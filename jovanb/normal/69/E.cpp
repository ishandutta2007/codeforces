#include <bits/stdc++.h>
using namespace std;

unordered_map <int, int> br;
set <int> seet;

int niz[100009];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> k;
    int x;
    for(int i=1; i<=n; i++) cin >> niz[i];
    for(int i=1; i<=k; i++){
        x = niz[i];
        br[x]++;
        if(br[x] == 1) seet.insert(x);
        else seet.erase(x);
    }
    int l=1, r=k;
    cerr << "Autput :\n";
    if(!seet.empty()) cout << *(seet.rbegin()) << "\n";
    else cout << "Nothing\n";
    while(r < n){
        l++;
        r++;
        x = niz[r];
        br[niz[l-1]]--;
        if(br[niz[l-1]] == 1) seet.insert(niz[l-1]);
        else seet.erase(niz[l-1]);
        br[x]++;
        if(br[x] == 1) seet.insert(x);
        else seet.erase(x);
        if(!seet.empty()) cout << *(seet.rbegin()) << "\n";
        else cout << "Nothing\n";
    }
    return 0;
}