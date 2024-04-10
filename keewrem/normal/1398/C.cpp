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
        string ss;
        cin >> ss;
        for(int i = 0; i < N; i++)v[i] = ss[i]-'0';
        set<int> s; multiset<int> ms;
        int k = 0;
        ms.insert(0); s.insert(0);
        for(int i = 0; i < N; i++){
            k += v[i];
            ms.insert(k-i-1); s.insert(k-i-1);
        }
        ll ans = 0;
        for(auto x: s){
            ans+=((ll)ms.count(x)*(ms.count(x)-1))/2;
        }
        cout << ans<<endl;
    }
    return 0;
}