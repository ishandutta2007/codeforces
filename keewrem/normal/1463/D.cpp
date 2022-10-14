#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vi v(2*N,-1);
        int a;
        for(int i = 0; i < N; i++){
            cin >> a; v[a-1]=1;
        }
        int m = 0,ans = N+1; a = 0;
        for(auto x: v){a+=x; m = max(m,a);}
        ans-=m;
        a= 0,m = 0;
        reverse(v.begin(),v.end());
        for(auto x: v){a+=x; m = max(m,a);}
        ans-=m;
        cout << ans <<"\n";
    }
    return 0;
}