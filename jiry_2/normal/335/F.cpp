#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int x[500100],m,n,f[500100],y[500100];
priority_queue<long long,vector<long long>,greater<long long> >Q;
int main(){
    scanf("%d",&m); for (int i=1;i<=m;i++) scanf("%d",&x[i]); sort(x+1,x+m+1);
    f[1]=x[1]; y[1]=1; n=1; long long tot=x[1];
    for (int i=2;i<=m;i++){
        if (x[i]!=x[i-1]) f[++n]=x[i]; y[n]++; tot+=x[i];
    }
    int now=0;
    for (int i=n;i;i--){
        int rem=now-Q.size()*2; rem=min(rem,y[i]); vector<int>S;
        for (int j=1;j<=rem;j++) S.push_back(f[i]);
        rem=min(now,y[i])-rem;
        for (int j=1;j<=rem;j+=2){
            long long k1=Q.top(); Q.pop();
            if (k1<f[i]){
                S.push_back(f[i]); if (j!=rem) S.push_back(f[i]);
            } else {
                S.push_back(k1); if (j!=rem&&f[i]*2-k1>0) S.push_back(f[i]*2-k1);
            }
        }
        for (int j=0;j<S.size();j++) Q.push(S[j]); now+=y[i];
    }
    long long ans=0; while (!Q.empty()){ans+=Q.top(); Q.pop();}
    cout<<tot-ans<<endl; return 0;
}