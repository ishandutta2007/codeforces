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
string s; int n;

int cnta, cntb, cntc;
int cnt0, cnt1;
bool rail[maxN];
bool lck;
bool unl;

void scn(char c){
    for(int i = 1; i <= n; i++){
        if(s[i] == c) rail[i] = !rail[i];
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> s;
        cnta = 0;
        cntb = 0;
        cntc = 0;
        n = s.size();
        s = "^" + s;
        for(int i = 1; i <= n; i++){
            rail[i] = 0;
        }
        unl = 0;
        for(int i1 = 0; i1 < 2; i1++){
        scn('A');
        for(int i2 = 0; i2 < 2; i2++){
        scn('B');
        for(int i3 = 0; i3 < 2; i3++){
        scn('C');
        lck = 0;
        cnt1 = 0;
        cnt0 = 0;
        for(int i = 1; i <= n; i++){
            if(rail[i]) cnt1++;
            else cnt0++;
            if(cnt0 > cnt1){
                lck = 1; break;
            }
            
        }
        if(lck || cnt0 != cnt1) continue;
        else{
            unl = 1;
        }
        
        }
        }
        }
        if(unl) cout << "YES\n";
        else cout << "NO\n";
    }
}