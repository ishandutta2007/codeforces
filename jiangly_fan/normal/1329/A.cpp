#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 2;
LL a[maxn], s[maxn];
void no(){
    cout << -1;
    exit(0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i += 1) cin >> a[i];
    for(int i = m; i; i -= 1) s[i] = s[i + 1] + a[i];
    if(s[1] < n) no();
    vector<int> v;
    int p = 0;
    for(int i = 1; i <= m; i += 1){
        while(s[i] + p < n) p += 1;
        p += 1;
        v.push_back(p);
        if(p + a[i] > n + 1) no();
    }
    for(int x : v) cout << x << " ";
    return 0;
}