#include <iostream>

using namespace std;

int n;
string f[100005], s[100005];
int p[100005];

string rf[100005], rs[100005];

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> f[i] >> s[i];
    for (int i = 1; i <= n; ++i){
        cin >> p[i];
        rf[i] = f[p[i]];
        rs[i] = s[p[i]];
    }
    /*
    for (int i = 1; i <= n; ++i){
        cout << " -> " << rf[i] << " " << rs[i] << endl;
    }
    */
    bool r1 = true, r2 = true;
    for (int i = 2; i <= n; ++i){
        bool cr1 = false, cr2 = false;
        if (rf[i] > rf[i - 1]) cr1 |= r1;
        if (rf[i] > rs[i - 1]) cr1 |= r2;
        if (rs[i] > rf[i - 1]) cr2 |= r1;
        if (rs[i] > rs[i - 1]) cr2 |= r2;
        r1 = cr1;
        r2 = cr2;
    }
    if (r1 || r2) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}