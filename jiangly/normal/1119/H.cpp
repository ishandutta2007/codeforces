// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
const int inv2=499122177;
void FWT(vector<int> &a){
    int n=a.size();
    for(int k=1;k<n;k<<=1){
        for(int i=0;i<n;++i){
            if(~i&k){
                int u=a[i]+a[i|k];
                int v=a[i]-a[i|k];
                a[i]=u;
                a[i|k]=v;
            }
        }
    }
}
void IFWT(vector<int> &a){
    int n=a.size();
    for(int k=1;k<n;k<<=1){
        for(int i=0;i<n;++i){
            if(~i&k){
                int u=1ll*(a[i]+a[i|k])*inv2%P;
                int v=1ll*(a[i]-a[i|k]+P)*inv2%P;
                a[i]=u;
                a[i|k]=v;
            }
        }
    }
}
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
void solve(vector<vector<int>> &a){
    int n=a.size();
    for(int i=0;i<n;++i){
        if(!a[i][i]){
            for(int j=i+1;;++j){
                if(a[j][i]){
                    swap(a[i],a[j]);
                    break;
                }
            }
        }
        int x=a[i][i];
        for(int j=i;j<=n;++j){
            a[i][j]/=x;
        }
        for(int j=0;j<n;++j){
            if(i!=j){
                int y=a[j][i];
                for(int k=i;k<=n;++k){
                    a[j][k]-=a[i][k]*y;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int x,y,z;
    cin>>x>>y>>z;
    vector<pair<int,int>>a;
    int sum=0;
    for(int i=0;i<n;++i){
        int a_i,b_i,c_i;
        cin>>a_i>>b_i>>c_i;
        sum^=a_i;
        a.emplace_back(a_i^b_i,a_i^c_i);
    }
    vector<vector<vector<int>>>eq(1<<k);
    for(int i=0;i<(1<<k);++i){
        eq[i].push_back({1,1,1,1,n});
    }
    vector<int>f(1<<k);
    for(int i=0;i<n;++i){
        ++f[a[i].first];
    }
    FWT(f);
    for(int i=0;i<(1<<k);++i){
        eq[i].push_back({1,1,-1,-1,f[i]});
    }
    f.assign(1<<k,0);
    for(int i=0;i<n;++i){
        ++f[a[i].second];
    }
    FWT(f);
    for(int i=0;i<(1<<k);++i){
        eq[i].push_back({1,-1,1,-1,f[i]});
    }
    f.assign(1<<k,0);
    for(int i=0;i<n;++i){
        ++f[a[i].first^a[i].second];
    }
    FWT(f);
    for(int i=0;i<(1<<k);++i){
        eq[i].push_back({1,-1,-1,1,f[i]});
    }
    vector<int>w(4);
    w[0]=(1ll*x+y+z)%P;
    w[1]=(1ll*x+y-z+P)%P;
    w[2]=(1ll*x-y+z+P)%P;
    w[3]=(1ll*x-y-z+P*2)%P;
    for(int i=0;i<(1<<k);++i){
        solve(eq[i]);
        f[i]=1;
        for(int j=0;j<4;++j){
            f[i]=1ll*f[i]*Pow(w[j],eq[i][j][4])%P;
        }
    }
    IFWT(f);
    for(int i=0;i<(1<<k);++i){
        cout<<f[i^sum]<<' ';
    }
    cout<<endl;
    return 0;
}