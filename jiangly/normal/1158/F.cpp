#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
const long long P2=(long long)P*P;
int u[2][3005][4096],dp[3005][3005],f[3005];
int Pow(int a,int b){
    int ans=1;
    for(;b;a=1ll*a*a%P,b>>=1){
        if(b&1){
            ans=1ll*ans*a%P;
        }
    }
    return ans;
}
int main(){
    int s=clock();
    int n,c;
    scanf("%d%d",&n,&c);
    vector<int>a(n);
    for(auto &i:a){
        scanf("%d",&i);
    }
    int k=n/c;
    if(c<=10){
        u[0][0][0]=1;
        int cur=0;
        for(int i=1;i<=n;++i){
            cur^=1;
            for(int j=0;j<=k;++j){
                if(j>0){
                    dp[j][i]=u[cur^1][j-1][((1<<c)-1)^(1<<(a[i-1]-1))];                    
                }
                for(int s=0;s<(1<<c);++s){
                    if((s&(1<<(a[i-1]-1)))==0){
                        u[cur][j][s]=u[cur^1][j][s];
                    }else{
                        u[cur][j][s]=((long long)u[cur^1][j][s]*2+u[cur^1][j][s^(1<<(a[i-1]-1))])%P;
                    }
                }
                u[cur][j][0]=(u[cur][j][0]+dp[j][i])%P;
            }
        }
    }else{
        vector<vector<int>>num(n);
        for(auto &i:num){
            i.resize(n);
        }
        vector<int>pw(n+1);
        pw[1]=1;
        for(int i=2;i<=n;++i){
            pw[i]=(pw[i-1]*2+1)%P;
        }
        vector<int>inv(n+1);
        for(int i=1;i<=n;++i){
            inv[i]=Pow(pw[i],P-2);
        }
        for(int i=0;i<n;++i){
            int res=1,cnt0=c;
            vector<int>cnt(c);
            for(int j=i;j<n;++j){
                if(cnt[a[j]-1]==0){
                    --cnt0;
                }else{
                    res=(long long)res*inv[cnt[a[j]-1]]%P;
                }
                if(cnt0==0){
                    num[i][j]=res;
                }
                ++cnt[a[j]-1];
                res=(long long)res*pw[cnt[a[j]-1]]%P;
            }
        }
        s=clock();
        dp[0][0]=1;
        for(int i=1;i<=k;++i){
            for(int j=i*c;j<=n;++j){
                long long sum=0;
                for(int l=j-1;l>=(i-1)*c;--l){
                    // if(clock()-s>=6000){
                        // fprintf(stderr,"Time Limit Exceed\n");
                        // exit(0);
                    // }
                    sum+=(long long)dp[i-1][l]*num[l][j-1];
                    if(sum>=P2){
                        sum-=P2;
                    }
                }
                dp[i][j]=sum%P;
            }
        }
    }
    f[0]=1;
    for(int i=0;i<n;++i){
        f[0]=(f[0]<<1)%P;
    }
    --f[0];
    for(int i=1;i<=k;++i){
        for(int j=n,l=1;j>=1;--j){
            f[i]=(f[i]+(long long)dp[i][j]*l)%P;
            l=(l<<1)%P;
        }
    }
    for(int i=0;i<=n;++i){
        printf("%d ",(f[i]-f[i+1]+P)%P);
    }
    puts("");
    fprintf(stderr,"time: %.3lf s\n",(double)(clock()-s)/CLOCKS_PER_SEC);
    return 0;
}