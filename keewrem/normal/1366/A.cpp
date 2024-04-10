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
ll a,b;

int main(){
    cin >> T;
    while(T--){
        cin >> a >> b;
        if(a < b)swap(a,b);
        if(a>=2*b){cout << b<<"\n"; continue;}
        ll k = (2*b-a)/3;
        ll r = 0;
        r+=k;
        b-=2*k;
        a-=k;
        r+=min(a/2,b);
        cout << r << "\n";
    }
    return 0;
}