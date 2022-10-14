#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll N,T;


int main(){
    cin >> T;
    while(T--){
        ll ans = 0;
        cin >> N;
        vi ct(N+1,0);
        vi v(N);
        for(auto& x: v)cin >> x;
        for(int i = 1; i < N-2; i++){
            ct[v[i-1]]++;
            int k = 0;
            for(int j = i+1; j < N; j++)if(v[j]==v[i])k++;
            for(int j = i+1; j < N; j++){
                if(v[j]==v[i])k--;
                ans+=ct[v[j]]*k;
            }
        }
        cout << ans<<"\n";

    }
    return 0;
}