#include <bits/stdc++.h>
using namespace std;
const int maxn=100000+5;
typedef pair<int ,int > P;
#define MP make_pair
char s[2][maxn];
bool vis[2][maxn];
int n,k;
pair<pair<int ,int >,int > q[maxn*200];
void bfs()
{
    int head=0,tail=0;
    q[head]=(MP(MP(0,1),1));
    vis[0][1]=true;
    while(head<=tail){
        pair<P,int> now=q[head];head++;
        //printf("now: x=%d y=%d tim=%d\n",now.first.first,now.first.second,now.second);
        int sx=now.first.first,sy=now.first.second;
        if(sy>=2 && now.second+1<=sy-1 && s[sx][sy-1]!='X' && !vis[sx][sy-1]){
            vis[sx][sy-1]=true;
            q[++tail]=(MP(MP(sx,sy-1),now.second+1));
        }
        if(sy<n && now.second+1<=sy+1 && s[sx][sy+1]!='X' && !vis[sx][sy+1]){
            vis[sx][sy+1]=true;
            q[++tail]=(MP(MP(sx,sy+1),now.second+1));
            if(sy+1==n) {printf("YES\n");exit(0);}
        }
        if(sy+1>n && now.second<=sy){
            printf("YES\n");exit(0);
        }
        if(sy<=n-k && now.second+1<=sy+k && s[(sx^1)][sy+k]!='X' && !vis[(sx^1)][sy+k]){
            //printf("getk: sx=%d sy=%d\n",(sx^1),sy+k);
            vis[(sx^1)][sy+k]=true;
            q[++tail]=(MP(MP((sx^1),sy+k),now.second+1));
            if(sy+k==n) {printf("YES\n");exit(0);}
        }
        if(sy>n-k/* && now.second<=n-k*/){
            //printf("sx=%d sy=%d\n",sx,sy+k);
            printf("YES\n");exit(0);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s[0]+1);
    scanf("%s",s[1]+1);
    bfs();
    printf("NO\n");
    return 0;
}