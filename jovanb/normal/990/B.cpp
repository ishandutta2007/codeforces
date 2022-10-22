#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int niz[200009];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> niz[i];
    sort(niz+1, niz+1+n);
    stack <int> stek;
    for(int i=1; i<=n; i++){
        while(!stek.empty()){
            int x = stek.top();
            if(niz[i] == x) break;
            if(niz[i] > x){
                if(niz[i] <= x+k){
                    stek.pop();
                    continue;
                }
                else break;
            }
        }
        stek.push(niz[i]);
    }
    cout << stek.size();
    return 0;
}