#include<bits/stdc++.h>
using namespace std;
const int maxn=250010;
int i,j,k,n,m,a[maxn],Max[19][maxn],Min[19][maxn],p[maxn],Ln[maxn];
string S;
int getMin(int L,int R){
    int Len=R-L+1;
    // cerr<<"getMin "<<L<<' '<<R<<' '<<Len<<' '<<Min[Ln[Len]][L]<<' '<<Min[Ln[Len]][R-(1<<Ln[Len])+1]<<endl;
    return p[min(Min[Ln[Len]][L],Min[Ln[Len]][R-(1<<Ln[Len])+1])];
}
int getMax(int L,int R){
    int Len=R-L+1;
    return p[max(Max[Ln[Len]][L],Max[Ln[Len]][R-(1<<Ln[Len])+1])];
}
int main(){
    int T;
    cin>>T;
    Ln[0]=-1;for(i=1;i<maxn;i++)Ln[i]=Ln[i/2]+1;
    cerr<<Ln[200000]<<endl;
    while(T--){
        cin>>n;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            p[a[i]]=i;
            Min[0][i]=Max[0][i]=a[i];
        }
        if(n==1){puts("0");continue;}
        for(i=1;i<=18;i++)
            for(j=1;j<=n-(1<<i)+1;j++)
                Max[i][j]=max(Max[i-1][j],Max[i-1][j+(1<<i-1)]);
        for(i=1;i<=18;i++)
            for(j=1;j<=n-(1<<i)+1;j++)
                Min[i][j]=min(Min[i-1][j],Min[i-1][j+(1<<i-1)]);
        k=0;
        for(int now=p[1],B=0;now>=2;){
            if(!B)now=getMax(1,now-1),++k,B^=1;
            else now=getMin(1,now-1),++k,B^=1;
        }
        for(int now=p[1],B=0;now<n;){
            // cerr<<"now="<<now<<endl;
            if(!B)now=getMax(now+1,n),++k,B^=1;
            else now=getMin(now+1,n),++k,B^=1;
        }
        cout<<k<<endl;
    }
}