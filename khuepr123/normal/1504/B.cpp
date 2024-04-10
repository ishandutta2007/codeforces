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


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        string s, t;
        cin >> s >> t;
        s += "0";
        t += "0";
        int pr1, pr2;
        pr1 = 0;
        pr2 = 0;
        bool choke = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') pr1++;
            if(s[i] == '0') pr2++;
            if((s[i] == t[i]) xor (s[i + 1] == t[i + 1])){
                if((i) % 2 == 0 || pr1 != pr2){
                    choke = 1;
                    break;
                }
            }
        }
        if(choke){
            cout << "NO";
        }
        else cout << "YES";
        cout << "\n";
    }
}