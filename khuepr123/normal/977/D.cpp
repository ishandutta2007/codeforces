#include<bits/stdc++.h>
using namespace std;

#define int long long
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
int n;
pair<int, int> pr[maxN];
int temp;

int fac(int i){
    temp = 0;
    while(i % 2 == 0){
        temp++; i /= 2;
    }
    return temp;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> pr[i].se;
        pr[i].fi = fac(pr[i].se);
        pr[i].se = mod - pr[i].se;
    }
    sort(pr + 1, pr + n + 1);
    
    for(int i = 1; i <= n; i++){
        cout << mod - pr[i].se << " ";
    }
}