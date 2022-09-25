#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000;
char s[maxn + 2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> (s + 1);
    vector<int> v;
    int n = strlen(s + 1);
    int l = 1, r = n;
    while(true){
        while(l <= n and s[l] != '(') l += 1;
        while(r >= 1 and s[r] != ')') r -= 1;
        if(l < r){
            v.push_back(l);
            v.push_back(r);
        }
        else break;
        l += 1;
        r -= 1;
    }
    if(v.empty()) cout << "0";
    else{
        cout << "1\n" << v.size() << "\n";
        sort(v.begin(), v.end());
        for(int x : v) cout << x << " ";
    }
    return 0;
}