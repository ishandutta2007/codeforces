#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define X first
#define Y second


const int N=60,M=5000;
const int inf=1e9+10;
const double eps=1e-12;


int n,m,L[N],R[N],prob[N];

double f[N][M];
int h[N][M];
double DP(int pos,int ti,double threshold){
    if (ti>m) return threshold;
    if (pos==n+1) return 0;
    if (h[pos][ti]) return f[pos][ti];
    h[pos][ti]=1;
    f[pos][ti]=min(threshold,((DP(pos+1,ti+L[pos],threshold)+L[pos])*prob[pos]+(DP(pos+1,ti+R[pos],threshold)+R[pos])*(100-prob[pos]))/100);
    return f[pos][ti];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>L[i]>>R[i]>>prob[i];
    double Lans=0,Rans=inf;
    for(int pa=1;pa<=300;pa++){
        memset(h,0,sizeof(h));
        double mid=(Lans+Rans)/2;
        double res=((DP(2,L[1],mid)+L[1])*prob[1]+(DP(2,R[1],mid)+R[1])*(100-prob[1]))/100;
//        cout<<mid<<" "<<res<<'\n';
        if (res>=mid+eps) Lans=mid;
        else Rans=mid;
    }
    printf("%.9f",Lans);
}