#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define X first
#define Y second


const int N=1e5+10;
const double eps=1e-12;
const int inf=2e8+10;


int n;
ll s;
struct info{
    ll need,v1,v2;
    info(ll _need=0,ll _v1=0,ll _v2=0){
        need=_need;
        v1=_v1;
        v2=_v2;
    }
};
vector <info> v[2];

bool comp(info a,info b){
    return a.v2-a.v1<b.v2-b.v1;
}
ll solve(){

    ll ans=0;
    for(int j=0;j<=1;j++){
        ll sum=0;
        for(int i=v[j].size();i>0;i--){
            sum+=v[j][i-1].need;
            if (sum>=s){
                ll rem=sum%s;
                ans+=(v[j][i-1].need-rem)*v[j][i-1].v2;
                v[j][i-1].need=rem;
                while (v[j].size()>i){
                    ans+=v[j].back().need*v[j].back().v2;
                    v[j].pop_back();
                }
                sum=0;i++;
            }
        }
    }
    ll fneed=0;
    for(int j=0;j<=1;j++)
        for(auto i:v[j]) fneed+=i.need;
    if (fneed>s){
        for(int j=0;j<=1;j++)
            for(auto i:v[j]) ans+=i.need*i.v2;
    }else{
        ll rans1=0,rans2=0;
        for(auto i:v[0]) {
            rans1+=i.need*i.v1;
            rans2+=i.need*i.v2;
        }
        for(auto i:v[1]){
            rans1+=i.need*i.v2;
            rans2+=i.need*i.v1;
        }
        ans+=max(rans1,rans2);
    }
    return ans;
}
int main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        int req,f1,f2;
        cin>>req>>f1>>f2;
        if (f1<f2) v[0].push_back(info(req,f1,f2));
        else v[1].push_back(info(req,f2,f1));
    }
    for(int j=0;j<=1;j++)
        sort(v[j].begin(),v[j].end(),comp);
    cout<<solve();
}