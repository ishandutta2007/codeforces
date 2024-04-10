//Oshvleiki Svlaiyoska Ranasku sachi
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<double,double> pdd;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=2e5+10;
pdd v[mn];
double cross(pdd a,pdd b){
    return a.first*b.second-a.second*b.first;
}
bool bad(pdd a,pdd b,pdd c){
    return cross({b.first-a.first,b.second-a.second},{c.first-b.first,c.second-b.second})>=0;
}
int main(){
    int n;
    double p,q;
    scanf("%d%lf%lf",&n,&p,&q);
    for(int i=1;i<=n;i++)scanf("%lf%lf",&v[i].first,&v[i].second);
    sort(v+1,v+1+n);
    double f=0,s=0;
    for(int i=1;i<=n;i++)f=max(f,v[i].first),s=max(s,v[i].second);
    v[0]={0,s},v[n+1]={f,0};
    vector<pdd>cvx;
    for(int i=0;i<=n+1;i++){
        while(cvx.size()>=2&&bad(cvx[cvx.size()-2],cvx[cvx.size()-1],v[i]))cvx.pop_back();
        cvx.push_back(v[i]);
    }
    double ang=atan2(q,p);
    int h;
    for(h=0;ang<=atan2(cvx[h].second,cvx[h].first);h++);
    double m=q/p;
    double dx=cvx[h].first-cvx[h-1].first,dy=cvx[h].second-cvx[h-1].second;
    double x=(dx*cvx[h].second-dy*cvx[h].first)/(dx*m-dy);
    printf("%.20lf",p/x);
}