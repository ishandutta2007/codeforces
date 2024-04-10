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
        vi vv = v;
        sort(vv.rbegin(),vv.rend());
        bool k = 0;
        for(int i = 0; i < N-1; i++)if(vv[i]==vv[i+1])k=1;
        for(int i = 0; i < N; i++)if(vv[i]!=v[i])k=1;
        if(k)cout << "YES\n";else cout << "NO\n";
    }
    return 0;
}