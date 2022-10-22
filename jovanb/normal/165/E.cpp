#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a[1000005];
int ima[4500005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        ima[a[i]] = a[i];
    }
    for(int i=1; i<(1<<22); i++){
        for(int j=0; j<22 && !ima[i]; j++){
            if(((1<<j) & i) && (ima[i ^ (1<<j)])) ima[i] = ima[i ^ (1<<j)];
        }
    }
    int g = (1<<22)-1;
    for(int i=1; i<=n; i++){
        if(ima[g^a[i]]) cout << ima[g^a[i]] << " ";
        else cout << "-1 ";
    }
    return 0;
}