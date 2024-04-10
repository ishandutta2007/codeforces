#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
ll x,y,k;

int main(){
    cin >> T;
    while(T--){
        cin >> x >> y >> k;
        cout << (k*(y+1)+x-3)/(x-1)+k<<"\n";
    }
    return 0;
}