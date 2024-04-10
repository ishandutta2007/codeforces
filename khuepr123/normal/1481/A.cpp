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
int n, a[maxN];
bool chk[maxN];
void typre(){
    for(int i = 0; i <= n + 3; i++){
        chk[i] = 0;
    }
}

int x, y, u, d, r, l;


signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> x >> y;
        string s;
        cin >> s;
        l = 0;
        u = 0;
        d = 0;
        r = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'U') u++;
            if(s[i] == 'L') l++;
            if(s[i] == 'D') d++;
            if(s[i] == 'R') r++;
            
        }
        
        if(x < 0) swap(l, r);
        if(y < 0) swap(u, d);
        if(u >= abs(y) && r >= abs(x)) cout << "YES\n";
        else cout << "NO\n";
    }
}