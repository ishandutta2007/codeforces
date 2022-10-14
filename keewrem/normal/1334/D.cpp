#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,T,K,l,r;
ll sos[400000];
void cyc(ll a, ll s, ll e){
    for(int i = 0; i < N-a; i++){
        sos[2*i] = a; sos[2*i+1]=a+i+1;
    }
    for(int i = max(s,0LL); (i < 2*(N-a)) && i < e; i++)cout<<sos[i]<<" ";
}
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        cin >> l >> r;
        ll curr = 0;
        for(int i = 1; i < N; i++){
            if(curr+2*(N-i)>=l && curr < r)cyc(i,l-curr-1,r-curr);
            curr += 2*(N-i);
        }
        if(r == N*(N-1)+1)cout << "1";
        cout << "\n";
    }
    return 0;
}