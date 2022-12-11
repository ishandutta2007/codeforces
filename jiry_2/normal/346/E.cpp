#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int a,n,p,h;
int find(int a,int n,int p){
    if (1ll*a*n<p) return max(a,p-a*n);
    int k1=1ll*a*n/p;
    if (1ll*a*n%p+a<=p/a*a) k1--; find(min(p%a,a-p%a),k1,a);
}
int main(){
    int t; scanf("%d",&t);
    for (;t;t--){
        scanf("%d%d%d%d",&a,&n,&p,&h); a=a%p; int ans;
        if (1ll*a*n<p) ans=a; else ans=find(a,n,p);
        if (ans<=h) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}