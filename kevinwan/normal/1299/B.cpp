#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=1e5+10;
int x[mn],y[mn];
int main(){
    int n;
    scanf("%d",&n);
    bool hail=1;
    for(int i=0;i<n;i++)scanf("%d%d",x+i,y+i);
    x[n]=x[0],y[n]=y[0];
    if(n&1)hail=0;
    for(int i=0;i<n/2;i++){
        if(x[i+1]-x[i]!=x[i+n/2]-x[i+1+n/2])hail=0;
        if(y[i+1]-y[i]!=y[i+n/2]-y[i+1+n/2])hail=0;
    }
    if(hail)printf("YES");
    else printf("NO");
}