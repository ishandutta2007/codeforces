#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool ima[1005][1005];
int a[1005][1005];

int n, m;

bool check(int k){
    for(int i=1; i<=m; i++){
        for(int j=1; j<=m; j++){
            ima[i][j] = 0;
        }
    }
    vector <int> vec;
    for(int i=1; i<=n; i++){
        vec.clear();
        for(int j=1; j<=m; j++){
            if(a[i][j] >= k){
                for(auto c : vec){
                    if(ima[c][j]) return 1;
                    ima[c][j] = 1;
                }
                vec.push_back(j);
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    int l=1, r=1e9, res=0;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            res = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << res;
    return 0;
}