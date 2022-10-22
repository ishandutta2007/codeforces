#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll pre[100005];
ll niz[100005];
ll ima[100005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        pre[i] = pre[i-1] + niz[i];
    }
    ll sum = pre[n];
    if(sum%3){
        cout << 0;
        return 0;
    }
    sum /= 3;
    ll res = 0;
    ll suf = 0;
    for(int i=n; i>=1; i--){
        if(pre[i] == sum) res += ima[i+2];
        suf += niz[i];
        if(suf == sum) ima[i]++;
        ima[i] += ima[i+1];
    }
    cout << res;
    return 0;
}