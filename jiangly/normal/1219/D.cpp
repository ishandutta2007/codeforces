#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int MAX_N=100000;
int n,k;
int x[MAX_N];
int a;
int c[MAX_N];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&x[i]);
    }
    scanf("%d",&a);
    for(int i=0;i<n;++i){
        scanf("%d",&c[i]);
    }
    priority_queue<int,vector<int>,greater<int>> h;
    LL ans=0;
    for(int i=0;i<n;++i){
        h.push(c[i]);
        while(!h.empty()&&k<x[i]){
            k+=a;
            ans+=h.top();
            h.pop();
        }
        if(k<x[i]){
            puts("-1");
            return 0;
        }
    }
    printf("%lld\n",ans);
    return 0;
}