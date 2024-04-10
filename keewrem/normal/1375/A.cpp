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
        vi v(N);
        for(auto& x: v)cin >> x;
        for(int i = 0 ; i < N; i++){
            if(i&1)v[i]=abs(v[i]);
            else v[i]=0-abs(v[i]);
        }
        for(auto x: v)cout << x <<" ";
        cout <<"\n";
    }
    return 0;
}