#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
bool mark[200]; int ray[200]; int n;

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n; for(int i = 1; i <= n * 2; i++){
            cin >> ray[i];
        }
        for(int i = 1; i <= n; i++){
            mark[i] =  0;
        }
        for(int i = 1; i <= 2 * n; i++){
            if(mark[ray[i]] == 1){
                continue;
            }
            else{
                cout << ray[i] << " "; mark[ray[i]] = 1;
            }
        }
        cout << "\n";
    }
}