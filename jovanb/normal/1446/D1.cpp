#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 200000;

int a[MAXN+5];
int bio[2*MAXN+5];
int ima[105];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    int mx = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        ima[a[i]]++;
        mx = max(mx, ima[a[i]]);
    }
    int naj = 0;
    for(int i=1; i<=100; i++){
        if(ima[i] == mx){
            naj = i;
        }
    }
    int res = 0;
    for(int d=1; d<=100; d++){
        if(d == naj) continue;
        for(int i=0; i<=2*n; i++) bio[i] = 0;
        bio[n] = 1;
        int tr = 0;
        for(int i=1; i<=n; i++){
            if(a[i] == d) tr--;
            else if(a[i] == naj) tr++;
            if(!bio[tr+n]) bio[tr+n] = i+1;
            else res = max(res, i - bio[tr+n] + 1);
        }
    }
    cout << res;
    return 0;
}