#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define push_back pb

char razlicit(char x, char y){
    if('a' != x && 'a' != y) return 'a';
    if('b' != x && 'b' != y) return 'b';
    return 'c';
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
    
    int n, t;
    cin >> n >> t;
    t = n-t;
    string a, b;
    cin >> a >> b;
    int dif = 0, same = 0;
    for(int i=0; i<n; i++){
        if(a[i] != b[i]) dif++;
        else same++;
    }
    //cout << dif << " " << same << endl;
    string res = "";
    for(int bb=0; bb<=min(t, same); bb++){
        int p = t-bb;
        //cout << p << " " << dif << endl;
        if(2*p > dif) continue;
        int pa = p, pb = p, istih = bb;
        for(int i=0; i<n; i++){
            if(a[i] == b[i]){
                if(istih){
                    istih--;
                    res += a[i];
                }
                else res += razlicit(a[i], b[i]);
            }
            else if(pa){
                pa--;
                res += a[i];
            }
            else if(pb){
                pb--;
                res += b[i];
            }
            else{
                res += razlicit(a[i], b[i]);
            }
        }
        cout << res;
        return 0;
    }
    cout << -1;
    return 0;
}