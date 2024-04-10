#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=105,maxm=1e5+5;
int a[maxn];
ll fib[maxm];
bool dfs(int n,int m,int p){
    // printf("%d %d %d\n",n,m,p);
    if (!~m) return true;
    for (int i=0;i<n;i++) if (i!=p&&a[i]>=fib[m]){
        a[i]-=fib[m];
        if (dfs(n,m-1,i)) return true;
        a[i]+=fib[m];
    }
    return false;
}
int main(){
    int tt;
    fib[0]=1;
    fib[1]=1;
    for (int i=2;i<maxm;i++) fib[i]=fib[i-1]+fib[i-2];
    scanf("%d",&tt);
    while (tt--){
        int n;
        scanf("%d",&n);
        ll sum=0;
        for (int i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        int m=0;
        while (sum>0) sum-=fib[m++];
        if (sum){
            puts("No");
            continue;
        }
        puts(dfs(n,m-1,-1)?"Yes":"No");
    }
    return 0;
}