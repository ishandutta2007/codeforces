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
        int ans = N;
        for(int i = N-1; i > 0; i--)ans =(ans+1+i)/2;
        cout << ans<<"\n";ans =N;
        for(int i = N-1; i > 0; i--){
            cout << ans << " "<<i << "\n";
            ans =(ans+1+i)/2;
        }
    }
    return 0;
}