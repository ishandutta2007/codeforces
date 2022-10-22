#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mn=1<<25;
const ll mod=1e9+7;
ll num[26];

int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    ll n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    ll sum=0;
    for(char c:s)sum+=1LL<<(c-'a');
    if(sum==t){
        printf("No");
        return 0;
    }
    for(char &c:s){
        num[c-'a']++;
        t+=1LL<<(c-'a');
    }
    t-=2LL<<(s.back()-'a');
    num[s.back()-'a']--;
    num[s[s.size()-2]-'a']--;
    if(t<0||t%2==1){
        printf("No");
        return 0;
    }
    t>>=1;
    ll r=0;
    for(int i=0;i<26;i++){
        r+=num[i];
        r-=t&1;
        r=(r+2)/2-1;
        t>>=1;
        if(r<0){
            printf("No");
            return 0;
        }
        cerr<<r<<' '<<t<<endl;
    }
    if(t<=r)printf("Yes");
    else printf("No");
}