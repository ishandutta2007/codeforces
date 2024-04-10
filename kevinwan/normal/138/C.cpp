#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef pair<ld,ld>pld;
const int mn=3e5+10;
const ll mod=1e9+7;
struct event{
    int a,t;
    double p;
};
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<event>v;
    for(int i=0;i<n;i++){
        int a,h,l,r;
        scanf("%d%d%d%d",&a,&h,&l,&r);
        v.push_back({a-h,0,1-l*.01});
        v.push_back({a,1,1-l*.01});
        v.push_back({a+1,0,1-r*.01});
        v.push_back({a+h+1,1,1-r*.01});
    }
    for(int i=0;i<m;i++){
        int b,z;
        scanf("%d%d",&b,&z);
        v.push_back({b,2,(double)z});
    }
    double ans=0,p=0;
    int no=0;
    sort(v.begin(),v.end(),[](event a,event b){if(a.a!=b.a)return a.a<b.a;return a.t<b.t;});
    for(event e:v){
        if(e.t==0){
            if(e.p==0)no++;
            else p+=log(e.p);
        }
        else if(e.t==1){
            if(e.p==0)no--;
            else p-=log(e.p);
        }
        else{
            if(!no)ans+=exp(p)*e.p;
        }
    }
    printf("%.20lf",ans);
}