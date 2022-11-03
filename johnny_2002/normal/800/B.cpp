#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int N=1e3+10;
const double eps=1e-10;

int n;
ii a[N];


ll sqr(ll x){return x*x;}
ii operator -(ii a,ii b){
    return ii(a.X-b.X,a.Y-b.Y);
}
double distance(ii a,ii b){
    return sqrt(sqr(a.X-b.X)+sqr(a.Y-b.Y));
}
double solve(){
    a[n]=a[0];
    a[n+1]=a[1];
    double ans=distance(a[1],a[0])/2;
    for(int i=0;i<n;i++) ans=min(ans,distance(a[i+1],a[i])/2);
    for(int i=0;i<n;i++){
        double base=distance(a[i],a[i+2]);
        ii p1=a[i+1]-a[i];
        ii p2=a[i+2]-a[i];
        ll S2=abs(1LL*p1.X*p2.Y-1LL*p1.Y*p2.X);
//        printf("%.9f\n",S2/base/)
        ans=min(ans,S2/base/2);
    }
    return ans;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i].X>>a[i].Y;
    printf("%.9f",solve());
}