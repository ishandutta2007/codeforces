// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int P=998244353,N=1<<16;
vector<int> rev(N),omega(N);
int Pow(int a,int b){
    int c=1;
    while(b){
        if(b&1){
            c=1ll*c*a%P;
        }
        a=1ll*a*a%P;
        b>>=1;
    }
    return c;
}
void NTT_Init(){
    for(int i=1;i<N;++i){
        rev[i]=(rev[i>>1]>>1)|((N>>1)*(i&1));
    }
    omega[0]=1;
    omega[1]=Pow(3,(P-1)/N);
    for(int i=2;i<N;++i){
        omega[i]=1ll*omega[i-1]*omega[1]%P;
    }
}
void NTT(vector<int> &a){
    for(int i=0;i<N;++i){
        if(rev[i]<i){
            swap(a[i],a[rev[i]]);
        }
    }
    for(int k=2;k<=N;k<<=1){
        vector<int> w(k);
        for(int i=0;i<k;++i){
            w[i]=omega[N/k*i];
        }
        for(int i=0;i<N;i+=k){
            int u,v;
            for(int j=0;j<(k>>1);++j){
                u=a[i|j];
                v=1ll*a[i|j|(k>>1)]*w[j]%P;
                a[i|j]=u+v;
                if(a[i|j]>=P){
                    a[i|j]-=P;
                }
                a[i|j|(k>>1)]=u-v;
                if(a[i|j|(k>>1)]<0){
                    a[i|j|(k>>1)]+=P;
                }
            }
        }
    }
}
void INTT(vector<int> &a){
    reverse(a.begin()+1,a.end());
    NTT(a);
    int inv=Pow(N,P-2);
    for(int i=0;i<N;++i){
        a[i]=1ll*a[i]*inv%P;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    NTT_Init();
    int n,k;
    cin>>n>>k;
    vector<vector<int>>dp(3,vector<int>(N));
    dp[0][0]=1;
    for(int i=1;i<=2;++i){
        for(int j=0;j<(N>>1);++j){
            dp[i][j]=(1ll*dp[i-1][j]+(j>=1?dp[i-1][j-1]:0)+(i>=2&&j>=1?dp[i-2][j-1]:0))%P;
        }
    }
    if(n<=2){
        for(int i=1;i<=k;++i){
            cout<<dp[n][i];
            if(i<k){
                cout<<' ';
            }
        }
        cout<<endl;
        return 0;
    }
    int l=0;
    while((1<<(l+2))<=n){
        ++l;
    }
    if(n&(1<<l)){
        dp[0]=dp[1];
        dp[1]=dp[2];
        for(int i=0;i<(N>>1);++i){
            dp[2][i]=(1ll*dp[1][i]+(i>=1?dp[1][i-1]+dp[0][i-1]:0))%P;
        }
    }
    while(l--){
        vector<vector<int>>f(5,vector<int>(N));
        NTT(dp[0]);
        NTT(dp[1]);
        NTT(dp[2]);
        for(int i=0;i<N;++i){
            f[0][i]=1ll*dp[0][i]*dp[0][i]%P;
            f[1][i]=1ll*dp[1][i]*dp[1][i]%P;
            f[2][i]=1ll*dp[2][i]*dp[2][i]%P;
            f[3][i]=1ll*dp[0][i]*dp[1][i]%P;
            f[4][i]=1ll*dp[1][i]*dp[2][i]%P;
        }
        for(int i=0;i<5;++i){
            INTT(f[i]);
        }
        for(int i=0;i<(N>>1);++i){
            dp[0][i]=f[1][i]+(i>=1?f[0][i-1]:0);
            if(dp[0][i]>=P){
                dp[0][i]-=P;
            }
            dp[1][i]=f[4][i]+(i>=1?f[3][i-1]:0);
            if(dp[1][i]>=P){
                dp[1][i]-=P;
            }
            dp[2][i]=f[2][i]+(i>=1?f[1][i-1]:0);
            if(dp[2][i]>=P){
                dp[2][i]-=P;
            }
        }
        for(int i=(N>>1);i<N;++i){
            dp[0][i]=0;
            dp[1][i]=0;
            dp[2][i]=0;
        }
        if(n&(1<<l)){
            dp[0]=dp[1];
            dp[1]=dp[2];
            for(int i=0;i<(N>>1);++i){
                dp[2][i]=(1ll*dp[1][i]+(i>=1?dp[1][i-1]+dp[0][i-1]:0))%P;
            }
        }
    }
    for(int i=1;i<=k;++i){
        cout<<dp[2][i];
        if(i<k){
            cout<<' ';
        }
    }
    cout<<endl;
    return 0;
}