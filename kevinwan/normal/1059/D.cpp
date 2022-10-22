#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e5+10;
long double x[mn],y[mn];
int n;
inline long double sq(long double x){return x*x;}
bool poss(long double r){
    long double l=-1e300,rr=1e300;
    for(int i=0;i<n;i++){
        if(r*2<y[i])return 0;
        l=max(l,x[i]-sqrt(2*r*y[i]-y[i]*y[i]));
        rr=min(rr,x[i]+sqrt(2*r*y[i]-y[i]*y[i]));
    }
    return rr>=l;
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int i;
    cin>>n;
    bool sgn=0;
    for(i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    for(i=1;i<n;i++){
            if(y[0]<0)y[i]*=-1;
            if(y[i]<0){
                printf("-1");
                return 0;
            }
        }
    y[0]=abs(y[0]);
    long double cur=0;
    for(long double d=1e18;d>=1e-20;d/=2){
        if(!poss(cur+d))cur+=d;
    }
    printf("%.20Lf",cur);
}