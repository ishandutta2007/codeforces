#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int br[10000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    while(m--){
        int x;
        cin >> x;
        br[x]++;
    }
    int mini = 1000000000;
    for(int i=1; i<=n; i++) mini = min(mini, br[i]);
    cout << mini;
    return 0;
}