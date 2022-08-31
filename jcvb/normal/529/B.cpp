#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
using namespace std;
void gn(int &x){
    char c;while((c=getchar())<'0'||c>'9');x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
}


int n;
struct pe{
    int w,h;
}p[1005];
int lim;
int seq[1005];
int main()
{
    scanf("%d",&n);
    lim=n/2;
    int st=0;
    for (int i=1;i<=n;i++){
        scanf("%d%d",&p[i].w,&p[i].h);
        st=max(st,min(p[i].w,p[i].h));
    }
    int mi = int(2e9);
    for (int maxh=st;maxh<=1000;maxh++){
        int must=0;
        int curw=0;
        int tot=0;
        for (int i=1;i<=n;i++){
            if(p[i].h>maxh){
                must++;
                curw+=p[i].h;
            }else if(p[i].w<=p[i].h || p[i].w>maxh)curw+=p[i].w;
            else{
                seq[++tot]=p[i].w-p[i].h;
                curw+=p[i].w;
            }
        }
        if(must>lim)continue;
        sort(seq+1,seq+1+tot);
        for (int i=tot;i>=1 && must+tot-i+1<=lim;i--){
            curw-=seq[i];
        }
        mi=min(mi,maxh*curw);
    }
    printf("%d\n",mi);
    return 0;
}