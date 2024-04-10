///
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int inf=0x3f3f3f3f,N=2e5+5;

int n,m;

int scan(int y,int x){
    printf("SCAN %d %d\n",y,x);
    fflush(stdout);
    scanf("%d",&x);
    return x;
}
int dig(int y,int x){
    printf("DIG %d %d\n",y,x);
    fflush(stdout);
    scanf("%d",&x);
    return x;
}
struct Point{
    int y,x;
}p[4];

int main(){
    #ifdef ONLINE_JUDGE
        //std::ios::sync_with_stdio(false);
    #else
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int s1=scan(1,1),s2=scan(1,m);
        int yo,xo,mn=inf;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int x=abs((i-1+j-1)*2-s1)+abs((i-1+m-j)*2-s2);
                if(x<mn){
                    mn=x;
                    yo=i,xo=j;
                }
            }
        }
        int s3=scan(1,xo),s4=scan(yo,1);
        p[0]={1+(s1-s4)/2,1+(s1-s3)/2};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i-1+j-1+p[0].y-1+p[0].x-1==s1&&i-1+m-j+p[0].y-1+m-p[0].x==s2){
                    p[1]={i,j};
                    break;
                }
            }
        }
        p[2]={p[0].y,p[1].x};
        p[3]={p[1].y,p[0].x};
        if(dig(p[0].y,p[0].x)){
            dig(p[1].y,p[1].x);
        }
        else{
            dig(p[2].y,p[2].x);
            dig(p[3].y,p[3].x);
        }
    }
    return 0;
}