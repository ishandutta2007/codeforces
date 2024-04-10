#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
#define N 100005
int n,sz;
typedef long long ll;
struct seg{int x0,y0,x1,y1,d,id;}s[N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char dc[4]={'U','R','D','L'};int gi(char c){for (int i=0;i<4;i++)if(dc[i]==c)return i;}
struct Q{
    int x,y,d,id;
    ll t;
}que[2*N];int q;
int cmsu(const seg&a,const seg&b){return max(a.y0,a.y1)>max(b.y0,b.y1);}
int cmsd(const seg&a,const seg&b){return min(a.y0,a.y1)<min(b.y0,b.y1);}
int cmsl(const seg&a,const seg&b){return min(a.x0,a.x1)<min(b.x0,b.x1);}
int cmsr(const seg&a,const seg&b){return max(a.x0,a.x1)>max(b.x0,b.x1);}
int cmpu(const Q&a,const Q&b){return a.y>b.y;}
int cmpd(const Q&a,const Q&b){return a.y<b.y;}
int cmpl(const Q&a,const Q&b){return a.x<b.x;}
int cmprr(const Q&a,const Q&b){return a.x>b.x;}
int cmp1(const seg&a,const seg&b){return a.id<b.id;}
int cmp2(const Q&a,const Q&b){return a.id<b.id;}

int seg[N*4];
inline void pd(int x){
    if(seg[x]){
        seg[x<<1]=seg[x<<1|1]=seg[x];
        seg[x]=0;
    }
}
int l1,r1,v,I;
void upd(int l,int r,int x){
    if(l1<=l && r<=r1)seg[x]=v;
    else{
        pd(x);
        int mid=l+r>>1;
        if(l1<=mid)upd(l,mid,x<<1);
        if(r1>mid)upd(mid+1,r,x<<1|1);
    }
}
int query(int l,int r,int x){
    if(l==r)return seg[x];
    else{
        pd(x);
        int mid=l+r>>1;
        if(I<=mid)return query(l,mid,x<<1);
        else return query(mid+1,r,x<<1|1);
    }
}
int ask(int i){
    I=i;
    return query(0,sz,1);
}
void cov(int l,int r,int v){
    if(l>r)swap(l,r);
    l1=l,r1=r;::v=v;
    upd(0,sz,1);
}
int next[2*N]={0};
int ti[2*N];
//int ansx[N],ansy[N];
int go[N][52]={0};ll tim[N][52];
int main()
{
    scanf("%d%d",&n,&sz);
    for (int i=1;i<=n;i++)scanf("%d%d%d%d",&s[i].x0,&s[i].y0,&s[i].x1,&s[i].y1),s[i].id=i;
    scanf("%d",&q);
    for (int i=1;i<=q;i++){
        char c;
        scanf("%d%d",&que[i].x,&que[i].y);
        while((c=getchar())<'A'||c>'Z');
        que[i].d=gi(c);
        que[i].id=i;
        cin>>que[i].t;
    }
    for (int i=1;i<=n;i++){
        int d;
        if(s[i].x1>s[i].x0)d=1;
        else if(s[i].x1<s[i].x0)d=3;
        else if(s[i].y1>s[i].y0)d=0;
        else d=2;
        s[i].d=d;
        que[i+q]=(Q){s[i].x1,s[i].y1,d,i+q,1000000000};
    }
    memset(seg,0,sizeof(seg));
    sort(que+1,que+1+n+q,cmpu);
    sort(s+1,s+1+n,cmsu);
    for (int y=sz,i=1,j=1;y>=0;y--){
        while(i<=n && max(s[i].y0,s[i].y1)==y){
            if(s[i].d!=0)cov(s[i].x0,s[i].x1,s[i].id);
            i++;
        }
        while(j<=n+q && que[j].y==y){
            if(que[j].d==0)next[que[j].id]=ask(que[j].x);
            j++;
        }
    }

    memset(seg,0,sizeof(seg));
    sort(que+1,que+1+n+q,cmpd);
    sort(s+1,s+1+n,cmsd);
    for (int y=0,i=1,j=1;y<=sz;y++){
        while(i<=n && min(s[i].y0,s[i].y1)==y){
            if(s[i].d!=2)cov(s[i].x0,s[i].x1,s[i].id);
            i++;
        }
        while(j<=n+q && que[j].y==y){
            if(que[j].d==2)next[que[j].id]=ask(que[j].x);
            j++;
        }
    }
    memset(seg,0,sizeof(seg));
    sort(que+1,que+1+n+q,cmprr);
    sort(s+1,s+1+n,cmsr);
    for (int x=sz,i=1,j=1;x>=0;x--){
        while(i<=n && max(s[i].x0,s[i].x1)==x){
            if(s[i].d!=1)cov(s[i].y0,s[i].y1,s[i].id);
            i++;
        }
        while(j<=n+q && que[j].x==x){
            if(que[j].d==1)next[que[j].id]=ask(que[j].y);
            j++;
        }
    }
    memset(seg,0,sizeof(seg));
    sort(que+1,que+1+n+q,cmpl);
    sort(s+1,s+1+n,cmsl);
    for (int x=0,i=1,j=1;x<=sz;x++){
        while(i<=n && min(s[i].x0,s[i].x1)==x){
            if(s[i].d!=3)cov(s[i].y0,s[i].y1,s[i].id);
            i++;
        }
        while(j<=n+q && que[j].x==x){
            if(que[j].d==3)next[que[j].id]=ask(que[j].y);
            j++;
        }
    }
    sort(s+1,s+1+n,cmp1);
    sort(que+1,que+1+q+n,cmp2);
    for (int i=1;i<=n+q;i++){
        int ne=next[i];
        if(que[i].d==0)ti[i]=(ne?min(s[ne].y0,s[ne].y1):sz)-que[i].y;
        else if(que[i].d==2)ti[i]=que[i].y-(ne?max(s[ne].y0,s[ne].y1):0);
        else if(que[i].d==1)ti[i]=(ne?min(s[ne].x0,s[ne].x1):sz)-que[i].x;
        else ti[i]=que[i].x-(ne?max(s[ne].x0,s[ne].x1):0);
        if(ti[i]<0)ti[i]=0;
    }
    for (int i=1;i<=q+n;i++){
        ll dt=min(que[i].t,(ll)ti[i]);
        que[i].x+=dx[que[i].d]*dt;
        que[i].y+=dy[que[i].d]*dt;
        que[i].t-=dt;
        if(que[i].t==0 || !next[i]){
            continue;
        }
        que[i].d=s[next[i]].d;
        if(s[next[i]].d==0)dt=s[next[i]].y1-que[i].y;
        else if(s[next[i]].d==2)dt=que[i].y-s[next[i]].y1;
        else if(s[next[i]].d==1)dt=s[next[i]].x1-que[i].x;
        else dt=que[i].x-s[next[i]].x1;
        dt=min((ll)dt,que[i].t);
        que[i].x+=dx[que[i].d]*dt;
        que[i].y+=dy[que[i].d]*dt;
        que[i].t-=dt;
    }
    for (int i=q+1;i<=q+n;i++){
        go[i-q][0]=next[i],tim[i-q][0]=1000000000-que[i].t;
    }
    for (int x=1;x<=51;x++)
        for (int i=1;i<=n;i++){
            go[i][x]=go[go[i][x-1]][x-1],tim[i][x]=tim[i][x-1]+tim[go[i][x-1]][x-1];
            if(tim[i][x]>1e15)tim[i][x]=1e15;
        }
    for (int i=1;i<=q;i++)if(que[i].t){
        int u=next[i];
        for (int j=51;j>=0;j--)if(tim[u][j]<=que[i].t && go[u][j]!=0){
            que[i].t-=tim[u][j];
            u=go[u][j];
        }
        if(u)que[i].x=s[u].x1,que[i].y=s[u].y1,que[i].d=s[u].d; 
        ll dt;
        if(u)dt=min(que[i].t,(ll)ti[u+q]);
        else if(!u){
            if(que[i].d==0)dt=sz-que[i].y;
            else if(que[i].d==2)dt=que[i].y;
            else if(que[i].d==1)dt=sz-que[i].x;
            else dt=que[i].x;
            dt=min(dt,que[i].t);
        }
        que[i].x+=dx[que[i].d]*dt;
        que[i].y+=dy[que[i].d]*dt;
        que[i].t-=dt;
        if(que[i].t==0 || !go[u][0]){
            continue;
        }
        que[i].d=s[go[u][0]].d;
        if(que[i].d==0)dt=s[go[u][0]].y1-que[i].y;
        else if(que[i].d==2)dt=que[i].y-s[go[u][0]].y1;
        else if(que[i].d==1)dt=s[go[u][0]].x1-que[i].x;
        else dt=que[i].x-s[go[u][0]].x1;
        dt=min((ll)dt,que[i].t);
        que[i].x+=dx[que[i].d]*dt;
        que[i].y+=dy[que[i].d]*dt;
        que[i].t-=dt;
    }
    for (int i=1;i<=q;i++)printf("%d %d\n",que[i].x,que[i].y);
    return 0;
}