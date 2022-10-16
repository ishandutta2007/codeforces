#include<bits/stdc++.h>
#define MAX   23
using namespace std;
struct pos {
    int x,y;
    pos(){}
    pos(const int &_x,const int &_y) {
        x=_x;y=_y;
    }
    bool operator == (const pos &a) const {
        return (x==a.x && y==a.y);
    }
    bool operator != (const pos &a) const {
        return (x!=a.x || y!=a.y);
    }
};
char dir[][5]={"RU","U","LU","R","L","RD","D","LD"};
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={1,0,-1,1,-1,1,0,-1};
pos s,f;
int c[MAX][MAX];
int l[MAX][MAX];
int t[MAX][MAX];
int r[MAX];
queue<pos> q;
void init(void) {
    char inp[3];
    scanf("%s",inp);
    s=pos(inp[1]-'0',inp[0]-'a'+1);
    scanf("%s",inp);
    f=pos(inp[1]-'0',inp[0]-'a'+1);
    int i,j;
    for (i=0;i<=9;i=i+1) {
        c[i][0]=1;
        c[0][i]=1;
        c[i][9]=1;
        c[9][i]=1;
    }       
}
void BFS(void) {
    while (!q.empty()) q.pop();
    int i,ux,uy;
    pos u;
    q.push(s);
    c[s.x][s.y]=1;
    while (!q.empty()) {
        u=q.front();q.pop();
        if (f==u) return;
        ux=u.x;uy=u.y;
        for (i=0;i<8;i=i+1)
            if (c[ux+dx[i]][uy+dy[i]]==0) {
                c[ux+dx[i]][uy+dy[i]]=1;                
                l[ux+dx[i]][uy+dy[i]]=l[ux][uy]+1;
                t[ux+dx[i]][uy+dy[i]]=i;
                q.push(pos(ux+dx[i],uy+dy[i]));
            }
    }
}
void trace(void) {
    printf("%d\n",l[f.x][f.y]);
    pos u=f;
    int i=0;
    int j;
    while (u!=s) {
        i++;
        j=t[u.x][u.y];
        r[i]=j;
        u.x=u.x-dx[j];
        u.y=u.y-dy[j];
    }
    while (i>0) {
        printf("%s\n",dir[r[i]]);
        i=i-1;
    }   
}
int main(void) {
    init();
    BFS();
    trace();
    return 0;
}