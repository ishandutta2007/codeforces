#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=1e6+10;
vector<pii>add[mn],rem[mn];
multiset<int>s[mn];
int sans[mn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,w,i,j,k,l;
    cin>>n>>w;
    for(i=0;i<n;i++){
        cin>>k;
        for(j=0;j<k;j++){
            int x;
            cin>>x;
            add[j].push_back({i,-x});
            rem[w-k+j+1].push_back({i,-x});
        }
        if(k==w)continue;
        add[0].push_back({i,0});
        rem[w-k].push_back({i,0});
        add[k].push_back({i,0});
    }
    ll rans=0;
    for(i=0;i<w;i++){
        vector<int>ch;
        for(pii p:add[i]){
            s[p.first].insert(p.second);
            ch.push_back(p.first);
        }
        for(pii p:rem[i]){
            s[p.first].erase(s[p.first].find(p.second));
            ch.push_back(p.first);
        }
        for(int x:ch){
            rans+=*s[x].begin()-sans[x];
            sans[x]=*s[x].begin();
        }
        printf("%lld ",-rans);
    }
}