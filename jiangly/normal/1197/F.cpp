#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int P=998244353;
const ll P_2=1ll*P*P;
template<class T>void chkmin(T &x,const T &y){
    if(y<x){
        x=y;
    }
}
template<class T>void chkmax(T &x,const T &y){
    if(y>x){
        x=y;
    }
}
template<class T>void sort(vector<T> &a){
    sort(a.begin(),a.end());
}
template<class T,class Cmp>void sort(vector<T> &a,Cmp cmp){
    sort(a.begin(),a.end(),cmp);
}
vector<vector<int>> operator +(const vector<vector<int>> &a,const vector<vector<int>> &b){
    int n=a.size();
    vector<vector<int>> c(n,vector<int>(n));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int x=a[i][j]+b[i][j];
            x>=P?x-=P:0;
            c[i][j]=x;
        }
    }
    return c;
}
vector<vector<int>> operator *(const vector<vector<int>> &a,const vector<vector<int>> &b){
    int n=a.size();
    vector<vector<int>> c(n,vector<int>(n));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            ll x=0;
            for(int k=0;k<n;++k){
                x+=1ll*a[i][k]*b[k][j];
                x>=P_2?x-=P_2:0;
            }
            c[i][j]=x%P;
        }
    }
    return c;
}
vector<int> operator *(const vector<vector<int>> &a,const vector<int> &b){
    int n=a.size();
    vector<int> c(n);
    for(int i=0;i<n;++i){
        ll x=0;
        for(int j=0;j<n;++j){
            x+=1ll*a[i][j]*b[j];
            x>=P_2?x-=P_2:0;
        }
        c[i]=x%P;
    }
    return c;
} 
void solve_single_test(int test_id=1){
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    int m;
    scanf("%d",&m);
    vector<vector<pair<int,int>>> cell(n);
    for(int i=0;i<m;++i){
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        cell[x-1].emplace_back(y-1,c-1);
    }
    for(int i=0;i<n;++i){
        sort(cell[i]);
    }
    vector<vector<int>> able(3,vector<int>(3));
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            scanf("%d",&able[i][j]);
        }
    }
    vector<vector<vector<int>>> trans(3);
    vector<vector<vector<int>>> sum(32);
    for(int color=0;color<3;++color){
        vector<vector<int>> a(64,vector<int>(64));
        vector<int> SG(3);
        for(int state=0;state<64;++state){
            SG[0]=state&3;
            SG[1]=(state>>2)&3;
            SG[2]=state>>4;
            vector<int> cnt(4);
            for(int i=0;i<3;++i){
                if(able[color][i]){
                    ++cnt[SG[i]];
                }
            }
            int next_SG;
            for(int i=0;i<4;++i){
                if(cnt[i]==0){
                    next_SG=i;
                    break;
                }
            }
            int next_state=((state<<2)|next_SG)&63;
            a[next_state][state]=1;
        }
        trans[color]=a;
    }
    sum[0]=trans[0]+trans[1]+trans[2];
    for(int i=1;i<32;++i){
        sum[i]=sum[i-1]*sum[i-1];
    }
    vector<int> dp(4);
    dp[0]=1;
    for(int i=0;i<n;++i){
        vector<int> g(64);
        g[63]=1;
        int cur=0;
        for(auto [x,color]:cell[i]){
            int delta=x-cur;
            int power=0;
            while(delta){
                if(delta&1){
                    g=sum[power]*g;
                }
                delta>>=1;
                ++power;
            }
            g=trans[color]*g;
            cur=x+1;
        }
        int delta=a[i]-cur;
        int power=0;
        while(delta){
            if(delta&1){
                g=sum[power]*g;
            }
            delta>>=1;
            ++power;
        }
        vector<int> ways(4);
        for(int i=0;i<64;++i){
            int x=ways[i&3]+g[i];
            x>=P?x-=P:0;
            ways[i&3]=x;
        }
        vector<int> next_dp(4);
        for(int i=0;i<4;++i){
            for(int j=0;j<4;++j){
                next_dp[i^j]=(next_dp[i^j]+1ll*dp[i]*ways[j])%P;
            }
        }
        dp=next_dp;
    }
    printf("%d\n",dp[0]);
}
void solve_multiple_tests(){
    int tests;
    scanf("%d",&tests);
    for(int i=1;i<=tests;++i){
        solve_single_test(i);
    }
}
int main(){
    solve_single_test();
    return 0;
}