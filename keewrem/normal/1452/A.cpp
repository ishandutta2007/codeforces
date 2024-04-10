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
ll x,y;

int main(){
    cin >> T;
    while(T--){
        cin >> x >> y;
        if(x > y)swap(x,y);
        y-=x;
        if(y == 0)cout << 2*x<<"\n";
        else cout << 2*x+2*y-1<<"\n";
    }
    return 0;
}