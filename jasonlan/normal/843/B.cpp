#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=50100;
int n,start,x;
int a[maxn];
int val,nxt;
void query(int p){
    printf("? %d\n",p);
    fflush(stdout);
    scanf("%d%d",&val,&nxt);
}
int main(){
    scanf("%d%d%d",&n,&start,&x);
    if(n<2000){
        int ans=2e9;
        for(int i=1;i<=n;++i){
            query(i);
            if(val>=x)ans=min(ans,val);
        }
        if(ans==2e9)ans=-1;
        printf("! %d",ans);
        fflush(stdout);
    }
    else{
        srand(time(NULL));
        for(int i=1;i<=n;++i)a[i]=i;
        random_shuffle(a+1,a+1+n);
        int ans=0,pr=start;
        for(int i=1;i<=1000;++i){
            query(a[i]);
            if(val<x&&val>ans)ans=val,pr=a[i];
        }
        while(pr!=-1&&ans<x){
            query(pr);
            ans=val;
            pr=nxt;
        }
        if(ans<x)ans=-1;
        printf("! %d",ans);
        fflush(stdout);
    }
    return 0;
}