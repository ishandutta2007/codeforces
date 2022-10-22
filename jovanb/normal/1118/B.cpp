#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll niz[200005];
ll pre[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        pre[i] = pre[i-1];
        if(i%2){
            pre[i] += niz[i];
        }
        else pre[i] -= niz[i];
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        ll sum1 = pre[i-1];
        ll sum2 = pre[n] - pre[i];
        sum2 = -sum2;
        if(sum1+sum2 == 0) cnt++;
    }
    cout << cnt;
    return 0;
}