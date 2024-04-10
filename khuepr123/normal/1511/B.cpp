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
int a, b, c;

int len(int num){
    int ct = 0;
    while(num){
        num = num / 10;
        ct++;
    }
    return ct;
}

int dud;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> a >> b >> c;
        a -= c;
        a++;
        b -= c;
        b++;
        dud = 1;
        for(int i = 1; i <= 1000; i++){
            dud = dud * 3;
            if(len(dud) == a){
                cout << dud; break;
            }
        }
        for(int i = 1; i < c; i++) cout << 0;
        cout << " ";
        dud = 1;
        for(int i = 1; i <= 1000; i++){
            dud = dud * 7;
            if(len(dud) == b){
                cout << dud; break;
            }
        }
        for(int i = 1; i < c; i++) cout << 0;
        cout << endl;
    }
}