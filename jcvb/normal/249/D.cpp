#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int n;
typedef long long ll;
struct node{
    ll x,y;
}p[100005];//y
void gn(int &x){
    char c;while((c=getchar())<'0'||c>'9');x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
}
int cmp(const node&a,const node&b){
    if(a.x==b.x)return a.y>b.y;
    else return a.x<b.x;
}
ll stk[100005];int top;
int main()
{
    int a,b,c,d;
    gn(n);
    gn(a);gn(b);gn(c);gn(d);
    for (int i=1;i<=n;i++){
        int x,y;gn(x);gn(y);
        p[i].x=1ll*b*y-1ll*a*x;
        p[i].y=1ll*c*x-1ll*d*y;
    }
    sort(p+1,p+1+n,cmp);
    top=0;
    for (int i=1;i<=n;i++){
        if(p[i].x<=0||p[i].y<=0)continue;
        if(!top || p[i].y>stk[top])stk[++top]=p[i].y;
        else{
            int l=1,r=top,mid;
            while(l<=r){
                mid=l+r>>1;
                if(p[i].y<=stk[mid])r=mid-1;
                else l=mid+1;
            }
            stk[l]=p[i].y;
        }
    }
    printf("%d\n",top);
    return 0;
}