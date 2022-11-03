#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using ld = long double;

const ll MAXN = 1000000007;

int r, b, u, ggggg;
int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int r1, b1, u1, ggggg1;
    char r2, b2, u2, ggggg2;
    r2 = 'R';
    b2 = 'B';
    u2 = 'Y';
    ggggg2 = 'G';
    r1 = s.find(r2);
    b1 = s.find(b2);
    u1 = s.find(u2);
    ggggg1 = s.find(ggggg2);
    for(int i = 0; i < s.length(); i++){
        if(s[i] != '!'){
            continue;
        }
        if(abs(i - r1) % 4 == 0){
            r++;
        }
        if(abs(i - b1) % 4 == 0){
            b++;
        }
        if(abs(i - u1) % 4 == 0){
            u++;
        }
        if(abs(i - ggggg1) % 4 == 0){
            ggggg++;
        }
    }
    cout << r << " " << b << " " << u << " " << ggggg << endl;
    return 0;
}