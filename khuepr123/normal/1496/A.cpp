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

string s, t;
string y;
int n;
int h;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> h;
        cin >> s;
        t = "";
        y = "";
        if(n <= h * 2){
            cout << "NO" << endl;
            continue;
        }
        for(int i = 0; i < h; i++) t += s[i];
        reverse(s.begin(), s.end());
        for(int i = 0; i < h; i++) y += s[i];
        if(t == y) cout << "YES\n";
        else cout << "NO\n";
    }
}