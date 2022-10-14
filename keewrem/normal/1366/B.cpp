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
ll N,X,M,a,b;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> X >> M;
        ll l = X,r = X;
        while(M--){
            cin >> a >> b;
            if(!(a>r || b < l))r = max(b,r);
            if(!(a>r || b < l))l = min(a,l);
        }
        cout << r-l+1<<"\n";
    }
    return 0;
}