#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <int> vec[100005];
int sz[100005];
int pos[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=k; i++){
        cin >> sz[i];
        for(int j=0; j<sz[i]; j++){
            int x;
            cin >> x;
            pos[x] = i;
            vec[i].push_back(x);
        }
    }
    ll res = 0;
    for(int i=n; i>=1; i--){
        int gde = pos[i];
        int k = sz[gde];
        if(k == i){
            cout << res;
            return 0;
        }
        res++;
        sz[gde]--;
        res += sz[gde] > 0;
        vec[gde].pop_back();
    }
    cout << res;
    return 0;
}