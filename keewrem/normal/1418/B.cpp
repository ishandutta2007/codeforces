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
int a,N;

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        vi v(N);
        for(auto &x: v)cin >> x;
        vi l(N);
        for(auto &x: l)cin >> x;
        vi srt;
        for(int i = 0; i < N; i++){
            if(!l[i])srt.pb(v[i]);
        }
        sort(srt.rbegin(),srt.rend());
        int j = 0;
        for(int i = 0; i < N; i++)if(!l[i])v[i]=srt[j++];
        for(auto x: v)cout << x << " ";
        cout << "\n";

    }
    return 0;
}