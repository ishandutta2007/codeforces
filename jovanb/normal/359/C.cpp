#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll sum;
ll a[100005];
int n;
ll p;

const int MOD = 1000000007;

ll pw(ll a, ll b){
    if(b == 0) return 1;
    ll res = pw(a, b/2);
    res = (res*res)%MOD;
    if(b%2) res = (res*a)%MOD;
    return res;
}

vector <ll> vec;
unordered_map <ll, ll> ima;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n >> p;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int i=1; i<=n; i++){
        ll x = sum - a[i];
        if(!ima[x]){
            vec.push_back(x);
        }
        ima[x]++;
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    ll res = 0;
    while(1){
        ll tren = vec[vec.size()-1];
        vec.pop_back();
        if(ima[tren]%p){
            res = tren;
            break;
        }
        else{
            if(!ima[tren+1]) vec.push_back(tren+1);
            ima[tren+1] += ima[tren]/p;
        }
    }
    res = min(res, sum);
    cout << pw(p, res) << endl;
    return 0;
}