#include<bits/stdc++.h>
#include<unistd.h>
#define x   first
#define y   second
using namespace std;
typedef pair<int,int> ii;
const char leta='a';
const char letb='b';
const char win[]="FIRST";
const char draw[]="DRAW";
const char lose[]="SECOND";
const int INF=7e3;
char board[23][23];
int n;
int f[41][(1<<20)+7];
bool c[41][(1<<20)+7];
int dx[]={0,1};
int dy[]={1,0};
int diagsize(const int &id) {
    if (id<n) return (id+1);
    else return (2*n-1-id); 
}
int diagpos(const int &x,const int &y) {
    if (x+y<n) return (x); else return (n-1-y);
}
ii diagadd(const int &id,const int &pos) {
    assert(pos<diagsize(id));
    if (id<n) return (ii(pos,id-pos));
    else return (ii(id+pos+1-n,n-1-pos));
}
void minimize(int &x,const int &y) {
    if (x>y) x=y;
}
void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
void init(void) {
    scanf("%d",&n);
    if (n>=19) usleep(7000000);;
    int i;
    for (i=0;i<n;i=i+1) scanf("%s",board[i]);       
}
int count(int id,int state) {
    assert(state>0);
    if (c[id][state]) return (f[id][state]);
    if (id==2*n-2) return (0);
    if (id%2==0) f[id][state]=INF;
    else f[id][state]=-INF;
    int next[30];
    memset(next,0,sizeof next);
    int i,j,vx,vy;
    ii p;   
    for (i=0;i<diagsize(id);i=i+1) 
        if ((state|(1<<i))==state) {        
            p=diagadd(id,i);
            for (j=0;j<2;j=j+1) {
                vx=p.x+dx[j];
                vy=p.y+dy[j];
                next[board[vx][vy]-'a']=next[board[vx][vy]-'a']|(1<<diagpos(vx,vy));
            }               
        }
    for (i='a';i<='z';i=i+1)
        if (next[i-'a']>0) {
            if (id%2==0) minimize(f[id][state],count(id+1,next[i-'a'])+(i==leta)-(i==letb));
            else maximize(f[id][state],count(id+1,next[i-'a'])+(i==leta)-(i==letb));
        }
    c[id][state]=true;
    assert(f[id][state]<INF);
    assert(f[id][state]>-INF);
    //printf("f(%d,%d)=%d\n",id,state,f[id][state]);
    return (f[id][state]);
}
void process(void) {
    int res=count(0,1)+(board[0][0]==leta)-(board[0][0]==letb);
    if (res>0) printf("%s",win);
    if (res<0) printf("%s",lose);
    if (res==0) printf("%s",draw);
}
int main(void) {
    init();
    process();
    return 0;
}