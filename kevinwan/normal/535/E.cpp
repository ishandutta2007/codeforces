#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=3e5+10;
struct Line{
    ll a,b;
    int ind;
};
__int128 one=1;
bool ded(Line a,Line b,Line c){
    return one*a.b*c.a*(b.b-c.b)*(b.a-a.a)<one*a.a*c.b*(a.b-b.b)*(c.a-b.a);
}
deque<Line>cvx;
int p[mn];
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
bool gud[mn];
int main(){
    cin.tie(0),cin.sync_with_stdio(0);
    iota(p,p+mn,0);
    int n;
    scanf("%d",&n);
    vector<Line>v;
    for(int i=1;i<=n;i++){
        ll a,b;
        scanf("%lld%lld",&a,&b);
        v.push_back({a,b,i});
    }
    sort(v.begin(),v.end(),[](Line a,Line b){if(a.a!=b.a)return a.a<b.a;return a.b>b.b;});
    for(Line l:v){
        if(cvx.size()&&cvx.back().a==l.a){
            if(l.b==cvx.back().b)p[l.ind]=f(cvx.back().ind);
            continue;
        }
        while(cvx.size()>=2&&ded(cvx[cvx.size()-2],cvx[cvx.size()-1],l))cvx.pop_back();
        cvx.push_back(l);
    }
    while(cvx.size()>=2&&cvx[0].b-cvx[1].b<=0)cvx.pop_front();
    for(Line l:cvx)gud[l.ind]=1;
    for(int i=1;i<=n;i++)if(gud[f(i)])printf("%d ",i);
}