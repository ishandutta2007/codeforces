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
int n; int a, b; int cnt; int k[maxN];



signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o; string s;
    while(o--){
        cin >> a >> b; bool x = 1;
        cin >> s; cnt = 0; int temp = 0; s = s + "0";
        string t = s;
        s = "0" + t;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0'){
                temp++;
            }
            else{
                if(temp > 0){
                k[cnt] = temp; cnt++; temp = 0;}
            }
        }
        if(temp > 0){
            k[cnt] = temp; cnt++;
        }
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0'){
                x = 0; break;
            }
        }
        if(x){
            cout << a << endl; continue;
        }
        if(cnt <= 1){
            cout << "0\n"; continue;
        }
        cnt -= 2;
        int sum = 0;
        sum = sum + (cnt + 1) * a;
        for(int i = 1; i <= cnt; i++){
            if(k[i] * b < a){
                sum = sum - a + k[i] * b;
            }
        }
        cout << sum << endl;
    }
}