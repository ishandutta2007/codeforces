#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair <ll,ll> pll;

int N,T,i,c,m;
long long v[40];
long long K,act;
int main(){
    cin >> T;
    while(T--){
        cin >> N >> K;
        for(i = 0; i < N; i++)cin >> v[i];
        act  = 1;
        m = 0;
        for(i = 0; act <= 1e16+1; i++){
            c = 0;
            for(int i = 0; i < N; i++){
                if(v[i]%(K*act)>=act)c++;
                if(v[i]%(K*act)>=2*act)m = 100;
            }
            m = max(m,c);
            act *= K;
        }
        if(m  > 1)cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}