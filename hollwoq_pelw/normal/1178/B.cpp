#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    s += 'o';
    long long n = s.length();
    vector<long long> w_o;
    w_o.push_back(0);
    int c = 0;// number of w
    long long w = 0;// total
    long long ans = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == 'v'){
            c ++;
        }else{
            c = max(0, c-1);
            ans += c*w_o[w_o.size()-1];
            w += c;
            c = 0;
            w_o.push_back(w_o[w_o.size()-1]+w);
        }
    }
    cout << ans << endl;
    //for (auto a:w_o) cout << a << ' ';
    return 0;
}