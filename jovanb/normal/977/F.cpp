#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map <ll, ll> res;
ll niz[300000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    ll maxres = 0;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        res[niz[i]] = max(res[niz[i]], res[niz[i]-1]+1);
        maxres = max(maxres, res[niz[i]]);
    }
    cout << maxres << "\n";
    ll trazen=0;
    ll r=0;
    stack <int> stek;
    for(int i=n; i>=1; i--){
        if(maxres == res[niz[i]]){
            trazen = niz[i];
            r = i;
            stek.push(i);
            break;
        }
    }
    for(int i=r-1; i>=1; i--){
        if(niz[i] == trazen-1){stek.push(i); trazen--;}
    }
    while(!stek.empty()){
        cout << stek.top() << " ";
        stek.pop();
    }
    return 0;
}