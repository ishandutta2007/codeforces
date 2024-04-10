#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
struct point{
    int x,y;
    void scan(){
        scanf("%d%d",&x,&y);
    }
};
struct line{
    point s,t;
    int type;
    void scan(){
        s.scan(); t.scan();
        if (s.x==t.x){
            if (s.y<t.y) type=0; else type=1;
        } else if (s.x<t.x) type=2; else type=3;
    }
}x[110000];
char getin(){
    char ch=getchar(); while (ch<'A'||ch>'Z') ch=getchar(); return ch;
}
struct query{
    point k1;
    int type; 
    long long t;
    void scan(){
        k1.scan(); char ch=getin(); 
        if (ch=='U') type=0; else if (ch=='D') type=1; else if (ch=='R') type=2; else type=3;
        scanf("%I64d",&t);
    }
}q[110000];
struct step{
    point t;
    int where;
    long long d;
}go[110000][54],A[110000];
struct atom{
    int where,w;
};
int operator < (const atom k1,const atom k2){
    return k1.w<k2.w;
}
set<atom>S;
vector<int>in[110000],out[110000],ask[110000];
int n,b,m,gox[4]={0,0,1,-1},goy[4]={1,-1,0,0};
long long lim=1e16;
void print(point k1,int k2,long long k3){
//  cout<<k1.x<<" "<<k1.y<<" "<<k2<<" "<<k3<<endl;
    k1.x=max(0ll,min(1ll*b,k1.x+k3*gox[k2]));
    k1.y=max(0ll,min(1ll*b,k1.y+k3*goy[k2]));
    printf("%d %d\n",k1.x,k1.y);
}
int init(point k1,point k2,point k3){
    if (k1.x==k2.x&&k1.x==k3.x){
        if (k1.y>=min(k2.y,k3.y)&&k1.y<=max(k2.y,k3.y)) return 1;
    }
    if (k1.y==k2.y&&k1.y==k3.y){
        if (k1.x>=min(k2.x,k3.x)&&k1.x<=max(k2.x,k3.x)) return 1;
    }
    return 0;
}
int main(){
    scanf("%d%d",&n,&b);
    for (int i=1;i<=n;i++) x[i].scan(); scanf("%d",&m);
    for (int i=1;i<=m;i++){
        q[i].scan(); //if (n==7&&b==10&&i==69) cout<<q[i].k1.x<<" "<<q[i].k1.y<<" "<<q[i].t<<" "<<q[i].type<<endl;
    }
    for (int i=0;i<=b+1;i++){in[i].clear(); out[i].clear(); ask[i].clear();}
    for (int i=1;i<=n;i++)
        if (x[i].type<=1){
            int k1=min(x[i].s.y,x[i].t.y),k2=max(x[i].s.y,x[i].t.y);
            in[k1].push_back(i); out[k2+1].push_back(i);
        } else{
            in[x[i].s.y].push_back(i); out[x[i].t.y+1].push_back(i);
            ask[x[i].s.y].push_back(i);
        }
    for (int i=1;i<=m;i++)
        if (q[i].type>1) ask[q[i].k1.y].push_back(i+n);
    S.clear();
    for (int i=0;i<=b;i++){
        for (int j=0;j<out[i].size();j++){
            int k1=out[i][j]; //cout<<"out "<<k1<<endl;
            if (x[k1].type<=1) S.erase((atom){0,x[k1].s.x}); else {
                S.erase((atom){0,x[k1].s.x}); S.erase((atom){0,x[k1].t.x});
            }
        }
        for (int j=0;j<in[i].size();j++){
            int k1=in[i][j]; //cout<<"in "<<k1<<endl;
            if (x[k1].type<=1) S.insert((atom){k1,x[k1].s.x}); else {
                S.insert((atom){k1,x[k1].s.x}); S.insert((atom){k1,x[k1].t.x});
            }
        }
        for (int j=0;j<ask[i].size();j++){
            int k1=ask[i][j];
            if (k1<=n){
                if (x[k1].type==2){
                    set<atom>::iterator k3=S.upper_bound((atom){0,x[k1].t.x}); 
                    if (k3==S.end()){
                        go[k1][0].t=(point){b+1,i}; go[k1][0].d=lim; continue;
                    }
                    atom k2=*k3;
                    go[k1][0].where=k2.where; go[k1][0].t=(point){k2.w,i}; go[k1][0].d=k2.w-x[k1].t.x;
                } else {
                    set<atom>::iterator k3=S.lower_bound((atom){0,x[k1].t.x});
                    if (k3==S.begin()){
                        go[k1][0].t=(point){-1,i}; go[k1][0].d=lim; continue;
                    }
                    k3--; atom k2=*k3;
                    go[k1][0].where=k2.where; go[k1][0].t=(point){k2.w,i}; go[k1][0].d=x[k1].t.x-k2.w;
                }
            } else {
                k1-=n;// cout<<"find "<<k1<<endl;
                if (q[k1].type==2){
                    set<atom>::iterator k3=S.upper_bound((atom){0,q[k1].k1.x-1}); 
                    if (k3==S.end()){
                        A[k1].t=(point){b+1,i}; A[k1].d=lim; continue;
                    }
                    atom k2=*k3;
                    A[k1].where=k2.where; A[k1].t=(point){k2.w,i}; A[k1].d=k2.w-q[k1].k1.x;
                } else {
                    set<atom>::iterator k3=S.lower_bound((atom){0,q[k1].k1.x+1});
                    if (k3==S.begin()){
                        A[k1].t=(point){-1,i}; A[k1].d=lim; continue;
                    }
                    k3--; atom k2=*k3;
                    A[k1].where=k2.where; A[k1].t=(point){k2.w,i}; A[k1].d=q[k1].k1.x-k2.w;
                }
            }
        }
    }
    for (int i=0;i<=b+1;i++){in[i].clear(); out[i].clear(); ask[i].clear();}
    for (int i=1;i<=n;i++)
        if (x[i].type<=1){
            in[x[i].s.x].push_back(i); out[x[i].s.x+1].push_back(i); ask[x[i].s.x].push_back(i);
        } else {
            int k1=min(x[i].s.x,x[i].t.x),k2=max(x[i].s.x,x[i].t.x);
            in[k1].push_back(i); out[k2+1].push_back(i);
        }
    for (int i=1;i<=m;i++)
        if (q[i].type<=1) ask[q[i].k1.x].push_back(i+n);
    S.clear();
    for (int i=0;i<=b;i++){
        for (int j=0;j<out[i].size();j++){
            int k1=out[i][j];
            if (x[k1].type>2) S.erase((atom){0,x[k1].s.y}); else {
                S.erase((atom){0,x[k1].s.y}); S.erase((atom){0,x[k1].t.y});
            }
        }
        for (int j=0;j<in[i].size();j++){
            int k1=in[i][j];
            if (x[k1].type>2) S.insert((atom){k1,x[k1].s.y}); else {
                S.insert((atom){k1,x[k1].s.y}); S.insert((atom){k1,x[k1].t.y});
            }
        }
        for (int j=0;j<ask[i].size();j++){
            int k1=ask[i][j];
            if (k1<=n){
                if (x[k1].type==0){
                    set<atom>::iterator k3=S.upper_bound((atom){0,x[k1].t.y}); 
                    if (k3==S.end()){
                        go[k1][0].t=(point){i,b+1}; go[k1][0].d=lim; continue;
                    }
                    atom k2=*k3;
                    go[k1][0].where=k2.where; go[k1][0].t=(point){i,k2.w}; go[k1][0].d=k2.w-x[k1].t.y;
                } else {
                    set<atom>::iterator k3=S.lower_bound((atom){0,x[k1].t.y});
                    if (k3==S.begin()){
                        go[k1][0].t=(point){i,-1}; go[k1][0].d=lim; continue;
                    }
                    k3--; atom k2=*k3;
                    go[k1][0].where=k2.where; go[k1][0].t=(point){i,k2.w}; go[k1][0].d=x[k1].t.y-k2.w;
                }
            } else {
                k1-=n;
                if (q[k1].type==0){
                    set<atom>::iterator k3=S.upper_bound((atom){0,q[k1].k1.y-1}); 
                    if (k3==S.end()){
                        A[k1].t=(point){i,b+1}; A[k1].d=lim; continue;
                    }
                    atom k2=*k3;
                    A[k1].where=k2.where; A[k1].t=(point){i,k2.w}; A[k1].d=k2.w-q[k1].k1.y;
                } else {
                    set<atom>::iterator k3=S.lower_bound((atom){0,q[k1].k1.y+1});
                    if (k3==S.begin()){
                        A[k1].t=(point){i,-1}; A[k1].d=lim; continue;
                    }
                    k3--; atom k2=*k3;
                    A[k1].where=k2.where; A[k1].t=(point){i,k2.w}; A[k1].d=q[k1].k1.y-k2.w;
                }
            }
        }
    }
    for (int i=1;i<54;i++)
        for (int j=1;j<=n;j++){
            step k1=go[j][i-1];
            if (k1.where==0){go[j][i]=k1; continue;}
            step k2=go[k1.where][i-1];
            go[j][i].where=k2.where;
            go[j][i].t=k2.t;
            go[j][i].d=min(lim,k1.d+k2.d+abs(x[k1.where].t.x-k1.t.x)+abs(x[k1.where].t.y-k1.t.y));
        //  cout<<i<<" "<<j<<" "<<go[j][i].d<<endl;
        }
    for (int i=1;i<=m;i++)
        if (A[i].where!=0&&init(q[i].k1,x[A[i].where].s,x[A[i].where].t)){
            A[i].t=q[i].k1; A[i].d=0;
        }
    for (int i=1;i<=m;i++){
    //  cout<<"ask "<<q[i].t<<" "<<A[i].d<<endl;
    //  if (n==7&&b==10&&i!=69) continue;
        if (q[i].t<=A[i].d){
            print(q[i].k1,q[i].type,q[i].t); continue;
        }
        point k1=A[i].t; long long rem=q[i].t-A[i].d; int where=A[i].where;// cout<<where<<" "<<A[i].d<<endl;
        for (int j=53;j>=0;j--)
            if (rem>=go[where][j].d+abs(x[where].t.x-k1.x)+abs(x[where].t.y-k1.y)){
            //  cout<<j<<" "<<k1.x<<" "<<k1.y<<" "<<rem<<" "<<where<<" "<<go[where][j].d<<" "<<endl;
                rem-=go[where][j].d+abs(x[where].t.x-k1.x)+abs(x[where].t.y-k1.y);
                k1=go[where][j].t; where=go[where][j].where;
            }
        print(k1,x[where].type,rem);
    }
    return 0;
}