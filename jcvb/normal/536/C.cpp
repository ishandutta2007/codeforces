#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<queue>
#include<map>
typedef long long ll;
#define mo 1000000007
void gn(int &x){
    char c;while((c=getchar())<'0'||c>'9');x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
}
int qp(int a,ll b){
    int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;
}
using namespace std;
int n;
struct ren{
    int id,k,b;
}a[222222];
int cmp(const ren &x,const ren&y){
    if(x.k==y.k)return x.b>y.b;
    return x.k<y.k;
}
int ok[222222]={0};
int stk[222222],top;


#define b1 (a[stk[top-1]].b)
#define b2 (a[stk[top]].b)
#define b3 (a[i].b)
#define k1 (a[stk[top-1]].k)
#define k2 (a[stk[top]].k)
#define k3 (a[i].k)
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d%d",&a[i].k,&a[i].b),a[i].id=i;
    sort(a+1,a+1+n,cmp);
    top=0;
    for (int i=1;i<=n;i++){
        if(i>1 && a[i].k==a[i-1].k)continue;
        while(top>=2 && 1ll*(b1*b2-b1*b3)*(k2*k3-k1*k3)<1ll*(b1*b3-b2*b3)*(k1*k3-k1*k2))top--;
        stk[++top]=i;
    }
    for (int i=1;i<=top;i++)ok[a[stk[i]].id]=1;
    for (int i=1;i<top;i++){
        if(a[stk[i]].b<=a[stk[i+1]].b)ok[a[stk[i]].id]=0;
        else break;
    }
    for (int i=2;i<=n;i++){
        if(a[i].k==a[i-1].k && a[i].b==a[i-1].b && ok[a[i-1].id])ok[a[i].id]=1;
    }
    for (int i=1;i<=n;i++){
        if(ok[i])printf("%d ",i);
    }
    putchar('\n');
    return 0;
}