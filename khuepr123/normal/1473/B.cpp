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
string mn, mx;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> s >> t; mn = ""; mx = "";
        for(int i = 0; i < t.size(); i++) mn += s;
        for(int i = 0; i < s.size(); i++) mx += t;
        if(mn != mx){
            cout << "-1\n"; continue;
        }
        int n = s.size(); int m = t.size();
        int v = __gcd(n, m);
        v = n * m / v;
        for(int i = 0; i < v; i++) cout << mn[i];
        cout << endl;
        
    }
}