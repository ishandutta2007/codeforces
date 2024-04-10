// Hydro submission #6185bcab31a17833ceda506f@1636154539970
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,mod=998244353;
int _,n,a[N];
vector<pair<int,int> > f,g;
int ceil(int a,int b){return (a+b-1)/b;}
int main() {
    scanf("%d",&_);
    while(_--){
        int ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        f.clear();
        g.clear();
        for(int i=n;i>=1;i--){
            for(auto pi:f){
                int k=ceil(a[i],pi.first);
                ans=(ans+1ll*(k-1)*pi.second%mod*i%mod)%mod;
                if(a[i]/k==g.back().first)g.back().second+=pi.second;
                else g.push_back(make_pair(a[i]/k,pi.second));
            }
            g.push_back(make_pair(a[i],1));
            f=g;
            g.clear();
        }
        printf("%d\n",ans);
    }
    return 0;
}