#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=5e3+10;
vector<ll>ans;
void solve(ll a,ll b){
    if(a==0||b==0){
        if(a+b!=1){
            printf("Impossible");
            exit(0);
        }
    }
    else if(a>b){
        ans.push_back(a/b);
        solve(a%b,b);
    }
    else{
        ans.push_back(b/a);
        solve(a,b%a);
    }
}
int main(){
    ll a,b;
    scanf("%lld%lld",&a,&b);
    solve(a,b);
    ans.back()--;
    bool af=(a>b);
    if(!ans.back())ans.pop_back();
    for(int i=0;i<ans.size();i++,af^=1){
        printf("%lld",ans[i]);
        printf("%c",af?'A':'B');
    }
}