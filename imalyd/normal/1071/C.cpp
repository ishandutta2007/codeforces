//Problem C
#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,f[N],l,r,x[N],y[N],z[N],t,T,xxx[N],lll[N],rrr[N],mmm[N];
void flip(int a,int b,int c){f[a]^=1;f[b]^=1;f[c]^=1;x[++t]=a;y[t]=b;z[t]=c;}
int dfs(int a,int mask){
    if(T<a)return !mask;
    if(dfs(a+1,mask))return 1;
    if(dfs(a+1,mask^xxx[a])){flip(lll[a],mmm[a],rrr[a]);return 1;}
    return 0;
}
int main(){
    scanf("%d",&n);l=1;r=n;
    for(int i=1;i<=n;i++)scanf("%d",&f[i]);
    while(1){
        if(r-l<10){//printf("dfs %d %d\n",l,r);
            //for(int i=1;i<=n;i++)printf("%d ",f[i]);printf("first\n");
            int m=1,ma=0;
            for(int i=l;i<=r;i++){if(f[i])ma|=m;m<<=1;}//printf("ma=%d\n",ma);
            for(int i=0;i<=r-l;i++)for(int j=i+2;j<=r-l;j+=2){
                int mid=(i+j)>>1;
                xxx[++T]=(1<<i)|(1<<mid)|(1<<j);//printf("%d %d %d %d\n",i,mid,j,xxx[T]);
                lll[T]=i+l;rrr[T]=j+l;mmm[T]=mid+l;//printf("%d %d %d\n",lll[T],mmm[T],rrr[T]);
            }
            dfs(1,ma);
            //for(int i=1;i<=n;i++)printf("%d ",f[i]);printf("final\n");
            //for(int i=l;i<=r-2;i++)if(f[i])flip(i,i+1,i+2);
            for(int i=l;i<=r;i++)if(f[i]){printf("NO");return 0;}
            break;
        }
        if(f[l]==0&&f[l+1]==0&&f[l+2]==0)l+=3;
        else if(f[l]==0&&f[l+1]==0&&f[l+2]==1)flip(l+2,l+3,l+4),l+=3;
        else if(f[l]==0&&f[l+1]==1&&f[l+2]==0)flip(l+1,l+3,l+5),l+=3;
        else if(f[l]==0&&f[l+1]==1&&f[l+2]==1)flip(l+1,l+2,l+3),l+=3;
        else if(f[l]==1&&f[l+1]==0&&f[l+2]==0)flip(l+0,l+3,l+6),l+=3;
        else if(f[l]==1&&f[l+1]==0&&f[l+2]==1)flip(l+0,l+2,l+4),l+=3;
        else if(f[l]==1&&f[l+1]==1&&f[l+2]==1)flip(l+0,l+1,l+2),l+=3;
        else if(f[l]==1&&f[l+1]==1&&f[l+2]==0){
            if(f[r]==0&&f[r-1]==0&&f[r-2]==0)r-=3;
            else if(f[r]==0&&f[r-1]==0&&f[r-2]==1)flip(r-2,r-3,r-4),r-=3;
            else if(f[r]==0&&f[r-1]==1&&f[r-2]==0)flip(r-1,r-3,r-5),r-=3;
            else if(f[r]==0&&f[r-1]==1&&f[r-2]==1)flip(r-1,r-2,r-3),r-=3;
            else if(f[r]==1&&f[r-1]==0&&f[r-2]==0)flip(r-0,r-3,r-6),r-=3;
            else if(f[r]==1&&f[r-1]==0&&f[r-2]==1)flip(r-0,r-2,r-4),r-=3;
            else if(f[r]==1&&f[r-1]==1&&f[r-2]==1)flip(r-0,r-1,r-2),r-=3;
            else if(f[r]==1&&f[r-1]==1&&f[r-2]==0){
                if((l^r)&1){
                    int mid=(l+r-1)>>1;
                    flip(l,mid,r-1),flip(l+1,mid+1,r);
                }else{
                    int mid=(l+r)>>1;
                    flip(l,mid,r),flip(l+1,mid,r-1);
                }
            }
        }
    }
    printf("YES\n%d",t);
    for(int i=1;i<=t;i++)printf("\n%d %d %d",x[i],y[i],z[i]);
    return 0;
}