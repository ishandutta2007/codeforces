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

int x, y;

int calc(int num){
    int res = 0;
    while(num){
        res += (num % 2);
        num = num / 2;
    }
    return res;
}

int mark;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> x >> y;
        bitset<30> bt1(x);
        bitset<30> bt2(y);
        int cnt1 = 0;
        int cnt2 = 0;
        bool prev = 0;
        if(x > y){
            cout << "NO\n"; continue;
        }
        int dif;
        dif = calc(x) - calc(y);
        for(int i = 29; i > -1; i--){
            if(bt1[i] & bt2[i]){
                bt1[i] = 0;
                bt2[i] = 0;
            }
            if(bt1[i] == 1 && bt2[i] == 0){
                prev = 1; break;
            }
            if(bt1[i] == 0 && bt2[i] == 1){
                bt1[i] = 1;
                mark = i; break;
            }
        }
        
        if(prev){
            cout << "NO\n"; continue;
        }
        
        if(dif) while(mark--){
            if(bt1[mark] == 1){
                bt1[mark] = 0; dif--;
            }
            // cout << 'e' << endl;
            if(dif == 0) break;
        }
        if(dif){
            cout << "NO\n"; continue;
        }
        prev = 0;
        // cout << bt1 << endl << bt2 << endl << endl;
        for(int i = 0; i < 30; i++){
            if(bt1[i]) cnt1++;
            if(bt2[i]) cnt2++;
            if(cnt1 < cnt2){
                prev = 1; break;
            }
        }
        if(prev) cout << "NO\n";
        else cout << "YES\n";
    }
    
}