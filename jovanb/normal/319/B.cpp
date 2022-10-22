#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll niz[100009];
ll crko[100009];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    stack <int> stek;
    int n;
    cin >> n;
    ll maxcrko = 0;
    crko[1] = -79;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        while(!stek.empty()){
            int j = stek.top();
            if(niz[j] > niz[i]){
                maxcrko = max(maxcrko, crko[i]+1);
                break;
            }
            else {
                stek.pop();
                crko[i] = max(crko[i], crko[j]+1);
            }
        }
        stek.push(i);
    }
    cout << maxcrko;
    return 0;
}