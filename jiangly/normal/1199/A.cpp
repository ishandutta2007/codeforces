// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,inf=1e9;
int n,x,y;
int a[N];
int main(){
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;++i){
        int mn=inf;
        for(int j=max(1,i-x);j<=min(n,i+y);++j){
            mn=min(mn,a[j]);
        }
        if(a[i]==mn){
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}