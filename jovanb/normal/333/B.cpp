#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int bc[1005];
int br[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    int res=0;
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        br[a] = 1;
        bc[b] = 1;
    }
    for(int i=2; i<n; i++){
        if(!br[i]) res++;
    }
    for(int i=2; i<n; i++){
        if(n%2 == 1 && i == n/2+1){
            if(br[i] && !bc[i]) res++;
            continue;
        }
        if(!bc[i]) res++;
    }
    cout << res;
    return 0;
}