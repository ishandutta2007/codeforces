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
#define int long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n; int a[maxN]; bool chk[maxN];
int t[maxN]; bool flag;
int td; int command; int pos; int cnt;

void typre(){
    for(int i = 0; i <= n + 2; i++){
        chk[i] = 0;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n; flag = 0; pos = 0; cnt = 0;
        for(int i = 1; i <= n; i++){
            //td and command is time till the moment
            cin >> t[i] >> a[i];
            
        }
        t[n + 1] = 4000000000;
        for(int i = 1; i <= n; i++){
            if(flag == 0){
                command = a[i]; td = abs(pos - command);
                flag = 1;
            }
            td = abs(pos - command);
            int x = 1;
            if(pos - command) x = 0 - abs(pos - command) / (pos - command);
            if(td < t[i + 1] - t[i]){
                int last = pos + td * x;
                if((last - a[i]) * (a[i] - pos) >= 0) cnt++;
                pos = last; flag = 0;
            }
            else if(td == t[i + 1] - t[i]){
                int last = pos + td * x;
                if((last - a[i]) * (a[i] - pos) >= 0) cnt++;
                pos = last; flag = 0;
            }
            else{
                int last = pos + (t[i + 1] - t[i]) * x;
                if((last - a[i]) * (a[i] - pos) >= 0) cnt++;
                td = td - t[i + 1] + t[i];
                flag = 1;
                pos = last;
            }
            
        }
        
        cout << cnt << endl;
    }
}