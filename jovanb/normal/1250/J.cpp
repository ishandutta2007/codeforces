#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int a[100005];
int b[100005];
int gde[100005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        cin >> b[i];
        gde[b[i]] = i;
    }
    int lst = 0, res = 0;
    for(int i=1; i<=n; i++){
        if(gde[a[i]] < lst) res++;
        else lst = gde[a[i]];
    }
    cout << res;
    return 0;
}