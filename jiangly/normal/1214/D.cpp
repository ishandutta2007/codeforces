#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n,vector<int>(m));
    vector<vector<int>> d1(n,vector<int>(m));
    vector<vector<int>> d2(n,vector<int>(m));
    d1[0][0]=1;
    d2[n-1][m-1]=1;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        for(int j=0;j<m;++j){
            if(s[j]=='.'){
                g[i][j]=1;
            }
        }
    }
    for(int i=1;i<m;++i){
        d1[0][i]=g[0][i]&d1[0][i-1];
    }
    for(int i=1;i<n;++i){
        d1[i][0]=g[i][0]&d1[i-1][0];
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<m;++j){
            d1[i][j]=g[i][j]&(d1[i-1][j]|d1[i][j-1]);
        }
    }
    if(d1[n-1][m-1]==0){
        cout<<0<<endl;
        return 0;
    }
    for(int i=m-2;i>=0;--i){
        d2[n-1][i]=g[n-1][i]&d2[n-1][i+1];
    }
    for(int i=n-2;i>=0;--i){
        d2[i][m-1]=g[i][m-1]&d2[i+1][m-1];
    }
    for(int i=n-2;i>=0;--i){
        for(int j=m-2;j>=0;--j){
            d2[i][j]=g[i][j]&(d2[i+1][j]|d2[i][j+1]);
        }
    }
    for(int s=1;s<=n+m-3;++s){
        int cnt=0;
        for(int i=max(0,s-m+1);i<=min(n-1,s);++i){
            int j=s-i;
            cnt+=(d1[i][j]&d2[i][j]);
        }
        if(cnt==1){
            cout<<1<<endl;
            return 0;
        }
    }
    cout<<2<<endl;
    return 0;
}