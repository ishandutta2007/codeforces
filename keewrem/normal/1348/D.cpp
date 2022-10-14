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
ll N;

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        ll B = 1, M = 1;
        vi sol;int res = 0;
        while(M < N){
            if(N-M > 2*B && N-M <= 4*B){
                sol.pb((N-M)/2-B);
                B = (N-M)/2;
            }else{
            sol.pb(min(N-M-B,B));
            B += min(N-M-B,B);
            }
            M+=B;
        }
        cout << sol.size()<<"\n";
        for(auto x: sol)cout << x << " ";
        cout << "\n";
    }
    return 0;
}