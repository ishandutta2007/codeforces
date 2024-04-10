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
ll a,b,c,d;

int main(){
    cin >> T;
    while(T--){
        cin >> a >> b >> c >> d;
        a-=b;
        if(a <= 0){cout << b << "\n"; continue;}
        if(d >= c){cout << -1 <<"\n"; continue;}
        cout << b + c*((a+c-d-1)/(c-d))<<"\n";
    }
    return 0;
}