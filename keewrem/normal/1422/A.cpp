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
ll a,b,c;

int main(){
    cin >> T;
    while(T--){
        cin >> a >> b >> c;
        cout << a + b + c - 1 <<"\n";
    }
    return 0;
}