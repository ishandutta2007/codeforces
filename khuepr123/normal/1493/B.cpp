#include<bits/stdc++.h>
using namespace std;

#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int h, m;
string s;
int h1, m1;
string s1, s2;
int a, b, c, d;

int inv[] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> h >> m >> s;
        s1 = "";
        s2 = "";
        s1 += s[0];
        s1 += s[1];
        s2 += s[3];
        s2 += s[4];
        h1 = stoi(s1);
        m1 = stoi(s2);
        while(1){
            a = h1 / 10;
            b = h1 % 10;
            c = m1 / 10;
            d = m1 % 10;
            // if(a > 9 || b > 9 || b > 9 || d > 9){
            //     cout << a << " " << b << " " << c << " " << d << endl;
            //     return 0;
            // }
            a = inv[a];
            b = inv[b];
            c = inv[c];
            d = inv[d];
            if(a != -1 && b != -1 && c != -1 && d != -1){
                if(d * 10 + c < h && b * 10 + a < m){
                    if(h1 < 9) cout << 0;
                    cout << h1 << ":";
                    if(m1 < 9) cout << 0;
                    cout << m1 << endl;
                    break;
                }
            }
            m1++;
            if(m1 >= m){
                m1 = 0;
                h1++;
            }
            if(h1 >= h){
                h1 = 0;
            }
        }
    }
}