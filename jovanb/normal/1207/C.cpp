#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve(){
    int n;
    ll a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int lst = -1;
    ll cost = (n+1)*b + n*a;
    //cout << cost << "\n";
    bool ima = 0;
    for(int i=0; i<n; i++){
        //cout << i << " " << cost << endl;
        if(s[i] == '0') continue;
        ima = 1;
        if(lst == -1){
            cost += a+2*b;
            lst = i;
            continue;
        }
        if(lst == i-1){
            cost += b;
            lst = i;
            continue;
        }
        cost += 2*b;
        int dist = i-lst;
        if(dist == 2){
            //cost += (dist-1)*b;
            lst = i;
            continue;
        }
        cost += min(2*a, (dist-2)*b);
        lst = i;
    }
    if(ima) cost += a;
    cout << cost << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
9 100000000 100000000
010101010
*/