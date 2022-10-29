#include<iostream>
#include<cmath> 
#include<cstdio>
#include<cstring> 
#include<algorithm>

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)
#define INF 0x3f3f3f3f

using namespace std;

int i,j,k,p,x,n,tt,a[500],g[20],tmp;
long long f[2050],ans,b[500];

int main(){
    cin>>n;
    rep(i,1,n)
        scanf("%d",&a[i]);
    rep(i,1,n)
        scanf("%d",&b[i]);
    ans=INF;
    rep(i,1,n){
        x=a[i];
        p=-1;
        rep(j,2,sqrt(a[i]))
            if (x%j==0){
                p++;
                g[p]=j;
                while (x%j==0)
                    x/=j;
                if (x==1)
                    break;
            }
        if (x!=1){
            p++;
            g[p]=x;
        }
        if (p==-1)  {
            if (b[i]<ans)
                ans=b[i];
            continue;
        }
//cout<<p<<endl;
        tt=(1<<(p+1))-1;
//cout<<tt<<endl;   
        rep(j,0,tt)
            f[j]=INF;
        f[0]=0;
        rep(j,1,n)
            if (i!=j){
                tmp=0;
                rep(k,0,p)
                    if (a[j]%g[k]!=0)
                        tmp+=1<<k;
//cout<<tmp<<endl;          
                rep(k,0,tt)
                    if ((f[k]!=INF)&&(f[k|tmp]>f[k]+b[j]))
                        f[k|tmp]=f[k]+b[j];
            }
        if (f[tt]+b[i]<ans)
            ans=f[tt]+b[i];
    }
    if (ans==INF)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    return 0;
}