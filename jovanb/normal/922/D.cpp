#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct deo{
    string str;
    ll brs;
    ll brh;
    bool operator<(const deo& x){
        if(x.brh == 0) return false;
        if(brh == 0) return true;
        if(brs == 0) return false;
        if(x.brs == 0) return true;
        return brs*x.brh > x.brs*brh;
    }
} niz[1000000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    string glavni="";
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> niz[i].str;
        for(int j=0; j<int(niz[i].str.size()); j++){
            if(niz[i].str[j] == 's') niz[i].brs++;
            else niz[i].brh++;
        }
    }
    sort(niz,niz+n);
    ll br=0, brz=0;
    for(int i=0; i<n; i++){
        glavni += niz[i].str;
    }
    n=glavni.size();
    for(int i=0; i<n; i++){
        if(glavni[i] == 's') brz++;
        else br += brz;
    }
    cout << br << "\n";
    return 0;
}