#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int mn=3e5+10;
pair<pll,int> a[mn];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%lld",&a[i].first.first);
    for(i=0;i<n;i++)scanf("%lld",&a[i].first.second),a[i].second=i+1;
    sort(a,a+n,greater<pair<pll,int>>());
    vector<int>ans;
    ans.push_back(a[0].second);
    for(i=1;i<n;i+=2){
        if(a[i].first.second>=a[i+1].first.second)ans.push_back(a[i].second);
        else ans.push_back(a[i+1].second);
    }
    printf("%d\n",ans.size());
    for(int x:ans)printf("%d ",x);
}