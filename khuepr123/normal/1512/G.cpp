#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxN = 1e7 + 3;
int a[maxN];
int mn[maxN];

signed main(){
    int o; cin >> o;
    for(int i = 1; i < maxN; i++){
        a[i] = 1;
        mn[i] = maxN;
    }
    for(int i = 2; i < maxN; i++){
        for(int j = i; j < maxN; j += i){
            a[j] += i;
        }
    }
    for(int i = 1; i < maxN; i++){
        if(a[i] < maxN)
        mn[a[i]] = min(mn[a[i]], i);
    }
    int x;
    while(o--){
        cin >> x;
        if(mn[x] == maxN) cout << -1;
        else cout << mn[x];
        cout << endl;
    }
}