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
ll N,x,k;
int main(){
    cin >> T;
    while(T--){
        cin >> N>> x;
        ll mx= 0;bool q = 0;
        while(N--){
            cin >> k;
            if(k == x)q = 1;
            mx = max(k,mx);
        }
        if(q){cout << "1\n";continue;}
        if(mx <= x)cout << (x-1)/mx+1<<"\n";
        else cout << "2\n";
    }
    return 0;
}