#include<iostream>
#include<cmath> 
#include<cstdio>
#include<cstring> 
#include<algorithm>

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)
#define INF 0x3f3f3f3f

using namespace std;

int i,j,k,p,qq,n,tot,h,t,tmp,tmph,MaxFlow,now,ans,oooo;
int high[1111],vh[1111],e[1111],q[100001],c[1001][1001],f[1001][1001];
int a[1001],b[1001],num[1001];
int qw[1001],opo[1001][1001],pop;

int is_Prime(int u){
    int ii;
    rep(ii,2,sqrt(u))
        if (u%ii==0)
            return 0;
    return 1;
}

int main(){
    cin>>n;
    tot=0;
    rep(i,1,n){
        scanf("%d",&a[i]);
        if (a[i]%2==0)
            tot++;
    }
    p=1;
    qq=tot+1;
    rep(i,1,n)
        if (a[i]%2==0){
            p++;
            b[p]=a[i];
            num[p]=i;
        }
        else{
            qq++;
            b[qq]=a[i];
            num[qq]=i;
        }
    if (2*tot!=n){
        cout<<"Impossible"<<endl;
        return 0;
    }
    rep(i,1,n+2)
    rep(j,1,n+2)
        c[i][j]=0;
    rep(i,2,tot+1)
        c[1][i]=2;
    rep(i,tot+2,n+1)
        c[i][n+2]=2;
    rep(i,2,tot+1)
    rep(j,tot+2,n+1)
        if (is_Prime(b[i]+b[j]))
            c[i][j]=1;
    n+=2;
    h=0;
    t=0;
    high[1]=n;
    vh[n]=1;
    rep(i,1,n){
        e[i]=c[1][i];
        f[1][i]=c[1][i];
        f[i][1]=-f[1][i];
        if ((e[i]>0)&&(i!=n)){
            t++;
            q[t]=i;
            vh[high[i]]++;
        }
    }
    while (h<t){
        h++;
        now=q[h];
        rep(i,1,n)
            if ((c[now][i]>f[now][i])&&(high[now]==high[i]+1)&&(e[now]>0)){
                tmp=e[now];
                if (tmp>c[now][i]-f[now][i])
                    tmp=c[now][i]-f[now][i];
                e[now]-=tmp;
                e[i]+=tmp;
                f[now][i]+=tmp;
                f[i][now]-=tmp;
                if ((e[i]==tmp)&&(i!=1)&&(i!=n)){
                    t++;
                    q[t]=i;
                }
            }
        if ((e[now]>0)&&(now!=1)&&(now!=n)){
            tmph=high[now];
            high[now]=INF;
            rep(i,1,n)
                if ((c[now][i]>f[now][i])&&(high[i]<high[now]))
                    high[now]=high[i];
            high[now]++;
            t++;
            q[t]=now;
            vh[tmph]--;
            vh[high[now]]++;
            if (vh[tmph]==0){
                rep(i,1,n)
                    if ((high[i]>tmph)&&(high[i]<n)){
                        vh[high[i]]--;
                        high[i]=n;
                        vh[n]++;
                    }
            }
        }
    }
    MaxFlow=0;
    rep(i,2,n)  
        MaxFlow+=f[1][i];
    if (MaxFlow!=2*tot){
        cout<<"Impossible"<<endl;
    }
    else{
        ans=0;
        rep(i,2,n-1)
            qw[i]=1;
        rep(i,2,tot+1)
            if (qw[i]){
                ans++;
                pop=1;
                oooo=0;
                j=i;
                do{
                    qw[j]=0;
                    opo[ans][pop]=j;
                    rep(k,tot+2,n-1)
                        if (f[j][k]&&(k!=oooo)){
                            oooo=j;
                            j=k;
                            break;
                        }
                    pop++;
                    opo[ans][pop]=j;
                    rep(k,2,tot+1)
                        if (f[j][k]&&(k!=oooo)){
                            oooo=j;
                            j=k;
                            break;
                        }
                    pop++;
                }while(j!=i);
                opo[ans][0]=pop-1;
            }
        cout<<ans<<endl;
        rep(i,1,ans){
            cout<<opo[i][0];
            rep(j,1,opo[i][0])
                printf(" %d",num[opo[i][j]]);
            cout<<endl;
        }
    }
    return 0;
}