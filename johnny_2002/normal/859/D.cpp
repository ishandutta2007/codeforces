#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> ii;

#define X first
#define Y second

const int N=64;
int wei[N][N];
double f[10][N],prob[10][N];
int mask[10][N];
int n;
double DP(int p1,int depth){
    if (depth==0) return prob[1][p1];
    if (mask[depth][p1]!=0) return f[depth][p1];
    mask[depth][p1]=1;

    double ans=0;
    int L=((p1>>depth)^1)<<depth;
    for(int i=0;i<(1<<depth);i++)
        ans=max(ans,DP(L+i,depth-1));
//    cout<<"?"<<depth<<" "<<p1<<" "<<ans<<'\n';
    ans+=prob[depth+1][p1]*(1<<depth);
//    cout<<"?"<<depth<<" "<<p1<<" "<<ans<<'\n';
    ans+=DP(p1,depth-1);
//    cout<<"?"<<depth<<" "<<p1<<" "<<ans<<'\n';
    f[depth][p1]=ans;
//    cout<<depth<<" "<<p1<<" "<<ans<<'\n';
    return ans;
}
int main(){
    cin>>n;
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<(1<<n);j++) cin>>wei[i][j];


    for(int i=0;i<(1<<n);i++) prob[0][i]=1;
    for(int j=0;j<n;j++)
        for(int i=0;i<(1<<n);i++){
            int L=(((i>>j)^1)<<j);
            for(int k=0;k<(1<<j);k++) prob[j+1][i]+=prob[j][L+k]*(wei[i][L+k]+.0)/100;
            prob[j+1][i]*=prob[j][i];

//            cout<<j+1<<" "<<i<<" "<<prob[j+1][i]<<'\n';
        }
    double ans=0;
    for(int i=0;i<(1<<n);i++)
        ans=max(ans,DP(i,n-1));
    printf("%.9f",ans);
}