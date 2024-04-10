#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cerr <<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"
const int N = 2e5+10;
int cnt[N];
int main(){
    int t=1,n,x;
    // sd(t);
    while(t--){
        sd(n);
        rep(i,0,n) sd(x), cnt[x]++;    
        int ans = 1;
        for(int i = 2;i<N;i++){
            int ans1 = 0;
            for(int j = i;j<N;j+=i) ans1 += cnt[j];
            ans = max(ans,ans1);    
        }
        pd(ans);
    }
}