#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct Pt{
    int x, y, ind;
    bool operator <(const Pt& P){
        return x < P.x;
    }
};

vector <Pt> vec[1005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int x, y;
        cin >> x >> y;
        vec[y/1000].push_back({x, y, i});
    }
    for(int i=0; i<=1000; i++){
        sort(vec[i].begin(), vec[i].end());
        if(i%2) reverse(vec[i].begin(), vec[i].end());
    }
    for(int i=0; i<=1000; i++) for(auto c : vec[i]) cout << c.ind << " ";
    return 0;
}