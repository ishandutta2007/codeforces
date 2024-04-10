#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

const int MAXN = 2e3+10;
char G[MAXN][MAXN];
bool visit[MAXN][MAXN];
int n,m,r,c,x,y;
int dir[4][2]{1,0,-1,0,0,-1,0,1};//0 1 2 3 
struct node{
    int x,y;
    int left,right;
};
int ans;
int BFS()
{
    deque<node> Q;
    Q.push_front(node{r,c,x,y});
    while(!Q.empty())
    {
        node now = Q.front();
        Q.pop_front();
        int tx,ty;
        for(int i = 0 ; i < 4 ; i++)
        {
            if(now.left ==0 &&i==2)continue;
            if(now.right ==0 &&i==3)continue;
            tx = now.x + dir[i][0];
            ty = now.y + dir[i][1];
            if((tx>=0&&tx<n&&ty>=0&&ty<m)&&!visit[tx][ty]&&G[tx][ty]!='*')
            {
                ans++;
                if(i == 0||i == 1)
                {
                    Q.push_front(node{tx,ty,now.left,now.right});
                }
                else{
                    Q.push_back(node{tx,ty,i==2?now.left-1:now.left,i==3?now.right-1:now.right});
                }
                visit[tx][ty] = true;
            }
        }
    }


}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d",&r,&c);
    scanf("%d%d",&x,&y);
    r--;c--;
    ans = 1;
    visit[r][c] = true;
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%s",&G[i]);
    }
    BFS();
//    for(int i = 0 ; i < n ; i++)
//    {
//       for(int j = 0 ; j < m ; j++)
//       {
//           cout<<visit[i][j];
//       }
//       cout<<endl;
//    }
    printf("%d\n",ans);
    return 0;
}