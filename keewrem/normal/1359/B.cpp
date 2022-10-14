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
ll N,M,X,Y;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> M >> X >> Y;
        Y = min(Y,2*X);
        string s;
        ll ans = 0;
        for(int i = 0; i < N; i++){
            cin >> s;
            for (int j =  0; j < M; j++){
                if(s[j]=='*')continue;
                else if(j < M-1 && s[j+1] == '.'){
                    ans+=Y; j++;
                }else{
                    ans+=X;
                }
            }
        }
        cout << ans << "\n";

    }
    return 0;
}