#include <bits/stdc++.h>
using namespace std;
deque<int> ast, pac;
bool check(int x){
    deque<int> cast = ast;
    for(auto p : pac){
        if(cast.empty()) break;
        int lm = cast.front();
        if(lm < p - x) return false;
        int rg;
        if(lm < p){
            int gl = p - lm;
            int rg1 = p + max(0, x - 2 * gl);
            int rg2 = p + (x - gl) / 2;
            rg = max(rg1, rg2);
        } else rg = p + x;
        while(!cast.empty() && cast.front() <= rg) cast.pop_front();
    }
    return cast.empty();
}
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == '*') ast.push_back(i + 1);
        if(s[i] == 'P') pac.push_back(i + 1);
    }
    int lo = 0;
    int hi = 2 * n;
    int ans = -1;
    while(lo <= hi){
        int md = (lo + hi) / 2;
        if(check(md)){
            hi = md - 1;
            ans = md;
        } else lo = md + 1;
    }
    cout << ans << endl;
    return 0;
}