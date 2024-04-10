#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin >> n;
    long long tas[n+1];
    tas[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> k;
        tas[i] = tas[i-1]+k;
    }
    long long max = *max_element(tas,tas+n+1);
    long long min = *min_element(tas,tas+n+1);
    long long cmin = count(tas,tas+n+1,min);
    long long cmax = count(tas,tas+n+1,max);
    
    if (min == 0 && cmin == 1 && max == tas[n] && cmax == 1){
            cout << "YES" << endl;
    }else cout << "NO" << endl;
}
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        solve();
    }
    return 0;
}