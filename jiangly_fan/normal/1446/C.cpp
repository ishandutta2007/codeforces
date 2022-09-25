#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
int f(vector<int>& a, int i){
    if(i == 0) return 0;
    vector<int> b[2];
    for(int x : a) b[(x >> i) & 1].push_back(x);
    if(b[0].empty()) return f(b[1], i - 1);
    if(b[1].empty()) return f(b[0], i - 1);
    return min(b[0].size() - 1 + f(b[1], i - 1), b[1].size() - 1 + f(b[0], i - 1));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& x : a) cin >> x;
    cout << f(a, 29);
    return 0;
}