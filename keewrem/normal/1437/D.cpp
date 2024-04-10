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
        for(auto &x: v)cin >> x;

        int h = 0, k= 1;
        vi vv;
        for(int i = 2; i < N; i++){
            if(v[i]>v[i-1])k++;
            else {vv.pb(k); k = 1;}
        }
        vv.pb(k);
        int l = 1, nl = 0,f = 1;
        for(auto x: vv){
            if(f){f = 0; h++;}
        //    cout << x <<" nl "<<nl<<" l "<<l<<"\n";
            l--; nl+=x;
            if(l == 0){
                l = nl; nl = 0; f = 1;
            }
        }

        cout << h <<"\n";
    }
    return 0;
}