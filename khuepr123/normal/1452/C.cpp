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
int n; int a[maxN];
int store[100]; int cnt;


signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o; string s;
    while(o--){
        cin >> s; cnt = 0; store[0] = 0; store[1] = 0; store[2] = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 40){
                store[0]++;
            }
            else if(s[i] == 91){
                store[1]++;
            }
            else if(s[i] == 41 && store[0] > 0){
                store[0]--; cnt++;
            }
            else if(s[i] == 93 && store[1] > 0){
                store[1]--; cnt++;
            }
            
        }
        cout << cnt << endl;
    }
}