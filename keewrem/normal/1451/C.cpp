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
ll N,K;
string a,b;
int main(){
    cin >> T;
    while(T--){
        cin >> N >> K>> a >> b;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vi c(26,0);
        for(auto x: a)c[x-'a']++;
        for(auto x: b)c[x-'a']--;
        int ans = 1;
        for(int i = 0; i < N; i++)if(a[i]>b[i])ans=0;
        for(auto x: c)if(abs(x)%K)ans =0;
        if(ans)cout <<"Yes\n";
        else cout <<"No\n";
    }
    return 0;
}