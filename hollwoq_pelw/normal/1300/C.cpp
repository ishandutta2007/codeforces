#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+100;

vector<ll>cnt[32];
map<ll,ll>mp;
int n;
ll a[N];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        mp[a[i]]++;
        for(int j=30;j>=0;j--) if(a[i]>>j&1) {
            cnt[j].push_back(a[i]);
        }
    }
    for(int i=30;i>=0;i--) if(cnt[i].size()==1&&mp[cnt[i][0]]>0) {
        printf("%lld ",cnt[i][0]);
        mp[cnt[i][0]]--;
    }
    for(auto v:mp) {
        int t=v.second;
        if(t)
        while(t>0) printf("%lld ",v.first),t--;
    }
}