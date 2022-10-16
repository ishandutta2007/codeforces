#include<bits/stdc++.h>
#define MAX   700
#define x   first
#define y   second
using namespace std;
typedef pair<int,int> ii;
int cnt[2*MAX+70][2*MAX+70];
bool inq[2*MAX+70][2*MAX+70];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n;
void push(queue<ii> &q,const ii &p) {
    if (inq[p.x+MAX][p.y+MAX]) return;
    inq[p.x+MAX][p.y+MAX]=true;
    q.push(p);
}
void simulate(void) {
    scanf("%d",&n);
    queue<ii> q;
    ii p;   
    int i,k;
    cnt[MAX][MAX]=n;
    q.push(ii(0,0));
    while (!q.empty()) {        
        p=q.front();q.pop();
        inq[p.x+MAX][p.y+MAX]=false;
        if (cnt[p.x+MAX][p.y+MAX]<4) continue;
        k=cnt[p.x+MAX][p.y+MAX]/4;
        for (i=0;i<4;i=i+1) {       
            cnt[p.x+dx[i]+MAX][p.y+dy[i]+MAX]+=k;
            push(q,ii(p.x+dx[i],p.y+dy[i]));
        }
        cnt[p.x+MAX][p.y+MAX]-=k*4;
    }   
}
int answer(const int &x,const int &y) {
    if (x<0) return (answer(-x,y));
    if (y<0) return (answer(x,-y));
    if (x>MAX) return (0);
    if (y>MAX) return (0);  
    return (cnt[x+MAX][y+MAX]);
}
void process(void) {
    int i,q,x,y;
    scanf("%d",&q);
    for (i=1;i<=q;i=i+1) {
        scanf("%d",&x);
        scanf("%d",&y);     
        printf("%d\n",answer(x,y));     
    }
}
int main(void) {
    simulate();
    process();
    return 0;
}