#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e3+10;
int a[mn];
double p[mn][mn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            p[i][j]=(a[i]>a[j]);
        }
    }
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);if(a>b)swap(a,b);
        for(int i=1;i<a;i++)p[i][a]=p[i][b]=(p[i][a]+p[i][b])*.5;
        for(int i=b+1;i<=n;i++)p[a][i]=p[b][i]=(p[a][i]+p[b][i])*.5;
        for(int i=a+1;i<b;i++){
            double l=p[a][i],r=p[i][b];
            p[a][i]=(l+1-r)*.5;
            p[i][b]=(1-l+r)*.5;
        }
        p[a][b]=.5;
    }
    double ans=0;
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans+=p[i][j];
    printf("%.20lf",ans);
}