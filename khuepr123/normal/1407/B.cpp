#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
const ll mod = 1000000007; int n; int a[1005]; int mx; bool chk[1005] = { }; int temp = 1;
int x, c, d, y, e, f; // d = final; c, y is temporary
int plc;
int solve(int a, int b){
    while(a && b){
        if(a < b){
            swap(a, b);
        }
        a = a % b;
    }
    a = a + b; return a;
}


int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n; cin >> a[1]; mx = a[1]; temp = 1; for(int i = 2; i <= n; i++){
            cin >> a[i];
            if(a[i] > mx){
                mx = a[i];
                temp = i;
            }
        }
        cout << mx << " "; chk[temp] = 1; d = a[temp]; int goal;
        for(int v = 2; v <= n; v++){
            goal = 0;
            for(int i = 1; i <= n; i++){
                if(chk[i]){
                    continue;
                }
                c = solve(d, a[i]);
                if(c > goal){
                    goal = c; f = i;
                }
            }
            cout << a[f] << " "; chk[f] = 1; d = goal;
        }
        cout << "\n";
        for(int i = 0; i <= 1004; i++){
            chk[i] = 0;
        }
    }
}