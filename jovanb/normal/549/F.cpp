#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 300000;
const int K = 1000000;

ll res;
int k;

int a[N+5];
int ima[K+5];

void solve(int l, int r){
    if(l == r) return;
    int mid = (l+r)/2;
    int mx = 0, sum = 0;
    vector <pair <int, int>> vec;
    for(int i=mid; i>=l; i--){
        mx = max(mx, a[i]);
        sum = (sum + a[i])%k;
        vec.push_back({mx, sum});
    }
    sort(vec.begin(), vec.end());
    mx = 0, sum = 0;
    int j = 0;
    for(int i=mid+1; i<=r; i++){
        while(j < vec.size() && vec[j].first < a[i]){
            res += ima[(vec[j].first - vec[j].second + k)%k];
            j++;
        }
        sum = (sum + a[i])%k;
        ima[sum]++;
    }
    while(j < vec.size()){
        res += ima[(vec[j].first - vec[j].second + k)%k];
        j++;
    }
    sum = 0;
    for(int i=mid+1; i<=r; i++){
        sum = (sum + a[i])%k;
        ima[sum] = 0;
    }
    vec.clear();
    mx = 0, sum = 0;
    for(int i=mid+1; i<=r; i++){
        mx = max(mx, a[i]);
        sum = (sum + a[i])%k;
        vec.push_back({mx, sum});
    }
    sort(vec.begin(), vec.end());
    mx = 0, sum = 0;
    j = 0;
    for(int i=mid; i>=l; i--){
        while(j < vec.size() && vec[j].first <= a[i]){
            res += ima[(vec[j].first - vec[j].second + k)%k];
            j++;
        }
        sum = (sum + a[i])%k;
        ima[sum]++;
    }
    while(j < vec.size()){
        res += ima[(vec[j].first - vec[j].second + k)%k];
        j++;
    }
    sum = 0;
    for(int i=mid; i>=l; i--){
        sum = (sum + a[i])%k;
        ima[sum] = 0;
    }
    vec.clear();
    solve(l, mid);
    solve(mid+1, r);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    solve(1, n);
    cout << res << "\n";
    return 0;
}