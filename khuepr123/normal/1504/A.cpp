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
        string s;
        cin >> s;
        string t1, t2;
        t1 = s + "a";
        t2 = t1;
        bool chk = 0;
        reverse(t2.begin(), t2.end());
        if(t1 == t2){
            t1 = "a" + s;
            t2 = t1;
           reverse(t2.begin(), t2.end());
            if(t1 == t2) chk = 1;
        }
        if(!chk) cout << "YES" << endl << t1 << endl;
        else cout << "NO\n";
    }
}