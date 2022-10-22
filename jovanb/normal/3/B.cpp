#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <pair <int, int>> vec[3];
ll pref[3][100005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, v;
    cin >> n >> v;
    for(int i=1; i<=n; i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back({b, i});
    }
    sort(vec[1].begin(), vec[1].end());
    reverse(vec[1].begin(), vec[1].end());
    sort(vec[2].begin(), vec[2].end());
    reverse(vec[2].begin(), vec[2].end());
    int a = vec[1].size();
    int b = vec[2].size();
    for(int i=0; i<a; i++){
        if(i == 0) pref[1][0] = vec[1][0].first;
        else pref[1][i] = pref[1][i-1] + vec[1][i].first;
    }
    for(int i=0; i<b; i++){
        if(i == 0) pref[2][0] = vec[2][0].first;
        else pref[2][i] = pref[2][i-1] + vec[2][i].first;
    }
    ll mx = 0;
    for(int x=0; x<=b && 2*x<=v; x++){
        int y = v - 2*x;
        y = min(y, a);
        //cout << pref[1][y-1] << " " << pref[2][x-1] << " " << y << " " << x << endl;
        ll res = pref[1][y-1] + pref[2][x-1];
        mx = max(mx, res);
    }
    cout << mx << "\n";
    for(int x=0; x<=b && 2*x<=v; x++){
        int y = v - 2*x;
        y = min(y, a);
        ll res = pref[1][y-1] + pref[2][x-1];
        if(mx == res){
            for(int i=0; i<y; i++) cout << vec[1][i].second << " ";
            for(int i=0; i<x; i++) cout << vec[2][i].second << " ";
            return 0;
        }
    }
    return 0;
}