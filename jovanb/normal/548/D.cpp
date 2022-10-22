#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int l[200005];
int r[200005];
int res[200005];
int niz[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> niz[i];
    stack <int> stek;
    for(int i=1; i<=n; i++){
        l[i] = 1;
        while(!stek.empty()){
            int j = stek.top();
            if(niz[j] < niz[i]){
                l[i] = j+1;
                break;
            }
            else stek.pop();
        }
        stek.push(i);
    }
    while(!stek.empty()) stek.pop();
    for(int i=n; i>=1; i--){
        r[i] = n;
        while(!stek.empty()){
            int j = stek.top();
            if(niz[j] < niz[i]){
                r[i] = j-1;
                break;
            }
            else stek.pop();
        }
        stek.push(i);
    }
    for(int i=1; i<=n; i++){
        int len = r[i]-l[i]+1;
        res[len] = max(res[len], niz[i]);
    }
    for(int i=n; i>=1; i--){
        res[i] = max(res[i], res[i+1]);
    }
    for(int i=1; i<=n; i++) cout << res[i] << " ";
    return 0;
}