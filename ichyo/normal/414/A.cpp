#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
vector<int> solve(int n, int k){
    if(k == 0){
        if(n <= 1) return vector<int>(n, 1);
        else       return vector<int>(1, -1);
    }
    if(n == 1) {
        if(k == 0) return vector<int>(n, 1);
        else       return vector<int>(1, -1);
    }
    int m = n / 2;
    if(k < m) {
        return vector<int>(1, -1);
    }
    // k >= m
    int first = k - m + 1; // 10^8
    vector<int> res;
    res.push_back(first);
    res.push_back(first * 2);
    for(int i = 0; i < n - 2; i++){
        res.push_back(900000000 + i);
    }
    return res;
}

void output(const vector<int>& v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        cout << v[i];
        if(i == n - 1) cout << endl;
        else cout << " ";
    }
}

int main(){
    int n, k;
    while(cin >> n >> k){
        vector<int> res = solve(n, k);
        output(res);
    }
    return 0;
}