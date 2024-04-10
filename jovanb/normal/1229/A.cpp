#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll niz[10005];
map <ll, bool> ima;
bool moze[10005];
ll b[10005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    for(int i=1; i<=n; i++){
        cin >> b[i];
    }
    for(int i=1; i<=n; i++){
        if(ima[niz[i]]){
            moze[i] = 1;
            for(int j=1; j<=n; j++){
                if((niz[j] & niz[i]) == niz[j]){
                    moze[j] = 1;
                }
            }
        }
        ima[niz[i]] = 1;
    }
    ll sum = 0;
    for(int i=1; i<=n; i++){
        sum += moze[i]*b[i];
    }
    cout << sum;
    return 0;
}