#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 500002;
ll a[MAXN], pref[MAXN], suff[MAXN];
ll sum;
ll ans;
vector<int> pr, sf;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i){
            pref[i] = pref[i - 1] + a[i];
        } else {
            pref[i] = a[i];
        }
    }
    sum = pref[n - 1];
    for(int i = n - 1; i > 0; i--){
        suff[i] = sum - pref[i - 1];
    }
    suff[0] = sum;
    for(int i = 0; i < n - 2; i++){
        if(pref[i] * 3 == sum){
            pr.push_back(i);
        }
    }
    for(int i = 2; i < n; i++){
        if(suff[i] * 3 == sum){
            sf.push_back(i);
        }
    }
    int i = 0;
    ans = 0;
    int j = 0;
    while(i < pr.size() && j < sf.size()){
        if(pr[i] + 1 < sf[j]){
            ans += sf.size() - j;
            i++;
        } else {
            j++;
        }
    }
    cout << ans;
    return 0;
}