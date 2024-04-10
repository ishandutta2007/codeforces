#include<iostream>
#include<cmath> 
#include<cstdio>
#include<cstring> 
#include<algorithm>

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)
#define INF 0x3f3f3f3f

using namespace std;

int n,m,i,j,flag;
long long a[120][120],b[120][120],p,q,ans,mmax,aa[120],bb[120];

int main(){
    cin>>n>>m;
    rep(i,1,n)
    rep(j,1,m)  
        scanf("%d",&b[i][j]);
    rep(i,1,n)
    rep(j,1,m-1)
        a[i][j]=b[i][j]-b[i][j+1];
    flag=1;
    ans=0;
    rep(j,1,m-1){
        p=-1;
        q=+1;
        rep(i,1,n){
            if (a[i][j]>=0){
                if ((p!=-1)&&(p!=a[i][j])){
                    flag=0;
                    break;
                }
                if (p==-1)
                    p=a[i][j];
            }
            else{
                if ((q!=1)&&(q!=a[i][j])){
                    flag=0;
                    break;
                }
                if (q==1)
                    q=a[i][j];
            }
        }
        if (flag){
            if ((p>-1)&&(q<0)){
                if ((ans!=0)&&(p-q!=ans)){
                    flag=0;
                    break;
                }
                if (ans==0)
                    ans=p-q;
            }
        }
    }
    mmax=0;
    if (flag){
        rep(i,1,n)
        rep(j,1,m)
            if (b[i][j]>=mmax)
                mmax=b[i][j];
    }
    if (ans==0)
        ans=mmax+1;
    if (ans<=mmax)
        flag=0;
    if (flag){
        cout<<"YES"<<endl;
        cout<<ans<<endl;
        aa[1]=0;
        bb[1]=b[1][1];
        rep(i,2,n)
            aa[i]=(((b[i][1]-b[i-1][1]+aa[i-1])%ans)+ans)%ans;
        rep(j,2,m)
            bb[j]=(((b[1][j]-b[1][j-1]+bb[j-1])%ans)+ans)%ans;
        rep(i,1,n-1)
            printf("%d ",aa[i]);
        cout<<aa[n]<<endl;
        rep(j,1,m-1)
            printf("%d ",bb[j]);
        cout<<bb[m]<<endl;
    }
    else
        cout<<"NO"<<endl;
    return 0;
}