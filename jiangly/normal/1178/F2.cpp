#include<bits/stdc++.h>
using namespace std;
using ll=long long;
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
template<class T>void unique(vector<T> &a){
    a.resize(unique(a.begin(),a.end())-a.begin());
}
int readInt(){
    int x=0;
    char c=getchar();
    while(!isdigit(c)){
        c=getchar();
    }
    while(isdigit(c)){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
string readString(){
    string s;
    char c=getchar();
    while(isspace(c)){
        c=getchar();
    }
    while(!isspace(c)){
        s+=c;
        c=getchar();
    }
    return s;
}
void solve_single_test(int test_id=1){
    const int P=998244353;
    const ll P_2=1ll*P*P;
    int n=readInt();
    int m=readInt();
    vector<int> c(m);
    for(int &c:c){
        c=readInt()-1;
    }
    unique(c);
    m=c.size();
    if(m>=n*2){
        puts("0");
        return;
    }
    vector<int> L(n,m);
    vector<int> R(n,-1);
    for(int i=0;i<m;++i){
        chkmin(L[c[i]],i);
        chkmax(R[c[i]],i);
    }
    vector<vector<int>> dp(m,vector<int>(m));
    for(int len=1;len<=m;++len){
        for(int l=0;l+len<=m;++l){
            int r=l+len-1;
            int ans=0;
            int color=n;
            for(int i=l;i<=r;++i){
                chkmin(color,c[i]);
            }
            if(l<=L[color]&&r>=R[color]){
                ll res=0;
                for(int x=l;x<=L[color];++x){
                    res+=1ll*(x>l?dp[l][x-1]:1)*(x<L[color]?dp[x][L[color]-1]:1);
                    res>=P_2?res-=P_2:0;
                }
                ans=res%P;
                res=0;
                for(int x=R[color];x<=r;++x){
                    res+=1ll*(x<r?dp[x+1][r]:1)*(x>R[color]?dp[R[color]+1][x]:1);
                    res>=P_2?res-=P_2:0;
                }
                ans=ans*(res%P)%P;
                int x=L[color];
                for(int i=x+1;i<=R[color];++i){
                    if(c[i]==color){
                        if(i-x>1){
                            ans=1ll*ans*dp[x+1][i-1]%P;
                        }
                        x=i;
                    }
                }
            }
            dp[l][r]=ans;
        }
    }
    printf("%d\n",dp[0][m-1]);
}
void solve_multiple_tests(){
    int n_tests;
    n_tests=readInt();
    for(int i=1;i<=n_tests;++i){
        solve_single_test(i);
    }
}
int main(){
    solve_single_test();
    return 0;
}