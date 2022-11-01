#include <iostream>
#include <sstream>
#include <string>
using namespace std;
constexpr int mod = 1000000007;
long long len[10], val[10];
int f[100001];
string t[100001];
int pow10(int n) {
    if(n == 0) return 1;
    int x = pow10(n / 2);
    if(n % 2) return (long long) x * x % mod * 10 % mod;
    else return (long long) x * x % mod;
}
int main(){
    cin.sync_with_stdio(false);
    f[0] = 0;
    cin >> t[0];
    int q;
    cin >> q;
    cin.get(); // \n
    for(int i = 1; i <= q; i++) {
        string line;
        getline(cin, line);
        stringstream sin(line);
        char x, y;
        sin >> f[i] >> x >> y >> t[i];
    }
    for(int i = 0; i < 10; i++) {
        len[i] = 1;
        val[i] = i;
    }
    for(int i = q; i >= 0; i--) {
        long long ln = 0, vl = 0;
        for(int j = 0; j < (int) t[i].size(); j++) {
            int x = t[i][j] - '0';
            ln = (ln + len[x]) % (mod - 1);
            vl = (vl * pow10(len[x]) % mod + val[x]) % mod;
        }
        len[f[i]] = ln;
        val[f[i]] = vl;
    }
    cout << val[0] << endl;
}