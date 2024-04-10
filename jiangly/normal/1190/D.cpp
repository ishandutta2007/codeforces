// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
class BIT{
private:
int n;
vector<int> a;
public:
BIT(int n):n(n){
    a.resize(n+1);
}
void add(int x,int y){
    while(x<=n){
        a[x]+=y;
        x+=x&-x;
    }
}
int sum(int x){
    int y=0;
    while(x){
        y+=a[x];
        x-=x&-x;
    }
    return y;
}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> x(n),y(n),vx,vy;
    for(int i=0;i<n;++i){
        cin>>x[i]>>y[i];
    }
    vx=x;
    sort(vx.begin(),vx.end());
    vx.resize(unique(vx.begin(),vx.end())-vx.begin());
    vy=y;
    sort(vy.begin(),vy.end());
    vy.resize(unique(vy.begin(),vy.end())-vy.begin());
    vector<vector<int>> px(vy.size());
    for(int i=0;i<n;++i){
        x[i]=lower_bound(vx.begin(),vx.end(),x[i])-vx.begin()+1;
        y[i]=lower_bound(vy.begin(),vy.end(),y[i])-vy.begin();
        px[y[i]].push_back(x[i]);
    }
    BIT t(vx.size());
    ll ans=0;
    set<int> sx;
    for(int i=vy.size()-1;i>=0;--i){
        sort(px[i].begin(),px[i].end());
        for(int j=0;j<px[i].size();++j){
            if(!sx.count(px[i][j])){
                sx.insert(px[i][j]);
                t.add(px[i][j],1);
            }
        }
        int l=sx.size();
        ans+=1ll*l*(l+1)/2;
        l=t.sum(px[i][0]-1);
        ans-=1ll*l*(l+1)/2;
        l=sx.size()-t.sum(px[i].back());
        ans-=1ll*l*(l+1)/2;
        for(int j=1;j<px[i].size();++j){
            l=t.sum(px[i][j]-1)-t.sum(px[i][j-1]);
            ans-=1ll*l*(l+1)/2;
        }
    }
    cout<<ans<<endl;
    return 0;
}