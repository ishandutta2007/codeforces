#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define gg if(n == 0) return 0;
#define gg2 if(n == 0) return;
int n, k;
vector<int> vc[33];
char ord(int i){
    return char(i - 1 + 'a');
}
int rem(int i, int j){
    return ((i + j) - 1) % k + 1;
}
void job(int i, int j){ gg2
    int dup = i;
    while(1){
        dup = rem(dup, j);
        cout << ord(dup);
        n--; gg2
        if(dup == i) return;
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i = 2; i <= k; i++){
        int h = __gcd(i, k);
        for(int j = 1; j <= h; j++){
            vc[j].pb(i);
        }
    }
    cout << ord(k);
    n--; gg
    while(1){
        for(int i = 1; i <= k; i++){
            cout << ord(i);
            n--; gg
            for(auto child : vc[i]){
                job(i, child); gg
            }
        }
    }
}