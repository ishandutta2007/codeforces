#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

string ff1, ff2;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        string s;
        ff1 = "";
        ff2 = "";
        cin >> n >> s;
        s = "*" + s;
        int pre = 0;
        int sum = 0;
        bool chk = 0;
        for(int i = 1; i <= n; i++){
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
        for(int i = 1; i <= n; i++){
            if(s[i] == '1') sum++;
        }
        if(s[1] == '1' || s[n] == '1'){
            cout << "NO\n"; continue;
        }
        for(int i = 1; i < n; i++){
            if(s[i] == '1') sum--;
            if(s[i] == '0') pre += 2;
            if(pre == ((2 * (n - i)) - (2 * sum))){
                cout << "YES\n";
                int pre1 = 0;
                int pre2 = 0;
                for(int j = 1; j <= i; j++){
                    if(s[j] == '0'){
                        pre1++;
                        pre2++;
                        ff1 += "(";
                        ff2 += "(";
                    }
                    else{
                        if(pre1 > pre2){
                        pre1--;
                        pre2++;
                        ff1 += ")";
                        ff2 += "(";
                        }
                        else{
                        pre1++;
                        pre2--;
                        ff1 += "(";
                        ff2 += ")";
                        }
                    }
                }
                for(int j = i + 1; j <= n; j++){
                    if(s[j] == '0'){
                        pre1--;
                        pre2--;
                        ff1 += ")";
                        ff2 += ")";
                    }
                    else{
                        if(pre1 > pre2){
                        pre1--;
                        pre2++;
                        ff1 += ")";
                        ff2 += "(";
                        }
                        else{
                        pre1++;
                        pre2--;
                        ff1 += "(";
                        ff2 += ")";
                        }
                    }
                }
                cout << ff1 << endl << ff2 << endl;
                chk = 1;
                break;
            }
        }
        if(!chk)
        cout << "NO\n";
    }
}