#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
using namespace std;
int n,m,k,now;
map<int,int>bo[110000],prego[5][110000];
struct atom{
    int x,y;
};
int operator < (atom k1,atom k2){
    return k1.x<k2.x;
}
set<atom>A[210000],B[210000];
int where1,where2,s1,s2,len,a[210000],lim=n+m;
char ch[10];
struct line{
    int x1,y1,x2,y2;
};
int operator < (const line k1,const line k2){
    return k1.x1<k2.x1;
}
vector<line>C[210000],D[210000],c[210000],d;
struct atom2{
    int x,y,w;
}y[210000];
int compare(atom2 k1,atom2 k2){
    return k1.x+k1.y<k2.x+k2.y;
};
void add(int k1,int k2){
    for (;k1<=lim;k1+=k1&(-k1)) a[k1]+=k2;
}
int find(int k){
    int num=0; for (;k;k-=k&(-k)) num+=a[k]; return num;
}
int main(){
//  freopen("data.in","r",stdin); freopen("data.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=k;i++){
        int k1,k2; scanf("%d%d",&k1,&k2); bo[k1][k2]=1;
        A[k1+k2].insert((atom){k1,k2}); B[k1-k2+m+1].insert((atom){k1,k2});
    }
    scanf("%d%d",&where1,&where2); scanf("%s",ch+1); s1=where1; s2=where2;
    if (ch[1]=='N'&&ch[2]=='E') now=1; else if (ch[1]=='N'&&ch[2]=='W') now=2; else if (ch[1]=='S'&&ch[2]=='E') now=3; else now=4;
    int pre=now,flag=0,ti=0;
    for (int i=0;i<=n+1;i++){
        bo[i][0]=1; bo[i][m+1]=1; int k1=i,k2=0; 
        A[k1+k2].insert((atom){k1,k2}); B[k1-k2+m+1].insert((atom){k1,k2});
        k1=i; k2=m+1;
        A[k1+k2].insert((atom){k1,k2}); B[k1-k2+m+1].insert((atom){k1,k2});
    }
    for (int i=0;i<=m+1;i++){
        bo[0][i]=1; bo[n+1][i]=1; int k1=0,k2=i;
        A[k1+k2].insert((atom){k1,k2}); B[k1-k2+m+1].insert((atom){k1,k2});
        k1=n+1; k2=i;
        A[k1+k2].insert((atom){k1,k2}); B[k1-k2+m+1].insert((atom){k1,k2});
    }
    while (1){
        if (prego[now][where1][where2]) break; prego[now][where1][where2]=1;
        if (now==1){
            set<atom>::iterator k1=A[where1+where2].lower_bound((atom){where1,0});
            int x,y,next,X,Y;
            if (k1==A[where1+where2].begin()){
                int dis=min(where1-1,m-where2); x=where1-dis; y=where2+dis; X=x; Y=y;
                if (x==1){
                    if (y==m) next=4; else {next=3; Y++;}
                } else {next=2; X--;}
            } else {
                k1--;
                x=(*k1).x+1; y=(*k1).y-1; X=x; Y=y;
                if (bo[x-1][y]){
                    if (bo[x][y+1]) next=4; else next=3;
                } else if (bo[x][y+1]) next=2; else next=4;
                if (next==3) Y++; else if (next==2) X--;
            }
            C[where1+where2].push_back((line){x,y,where1,where2});
//          cout<<where1<<" "<<where2<<" "<<x<<" "<<y<<endl;
            now=next; where1=X; where2=Y; continue;
        } else if (now==2){
            set<atom>::iterator k1=B[where1-where2+m+1].lower_bound((atom){where1,0});
            int x,y,next,X,Y;
            if (k1==B[where1-where2+m+1].begin()){
                int dis=min(where1-1,where2-1); x=where1-dis; y=where2-dis; X=x; Y=y;
                if (x==1){
                    if (y==1) next=3; else {next=4; Y--;} 
                } else {next=1; X--;}
            } else {
                k1--;
                x=(*k1).x+1; y=(*k1).y+1; X=x; Y=y;
                if (bo[x-1][y]){
                    if (bo[x][y-1]) next=3; else next=4;
                } else if (bo[x][y-1]) next=1; else next=3;
                if (next==4) Y--; else if (next==1) X--;
            }
            D[where1-where2+m].push_back((line){x,y,where1,where2});
//          cout<<where1<<" "<<where2<<" "<<x<<" "<<y<<endl;
            now=next; where1=X; where2=Y; continue;
        } else if (now==3){
            set<atom>::iterator k1=B[where1-where2+m+1].upper_bound((atom){where1,0});
            int x,y,next,X,Y;
            if (k1==B[where1-where2+m+1].end()){
                int dis=min(n-where1,m-where2); x=where1+dis; y=where2+dis; X=x; Y=y;
                if (x==n){
                    if (y==m) next=2; else {next=1; Y++;}
                } else {next=4; X++;}
            } else {
                x=(*k1).x-1,y=(*k1).y-1; X=x; Y=y;
                if (bo[x][y+1]){
                    if (bo[x+1][y]) next=2; else next=4;
                } else if (bo[x+1][y]) next=1; else next=2;
                if (next==1) Y++; else if (next==4) X++;
            }
            D[where1-where2+m].push_back((line){where1,where2,x,y});
//          cout<<where1<<" "<<where2<<" "<<x<<" "<<y<<endl;
            now=next; where1=X; where2=Y; continue;
        } else if (now==4){
            set<atom>::iterator k1=A[where1+where2].upper_bound((atom){where1,0});
            int x,y,next,X,Y;
            if (k1==A[where1+where2].end()){
                int dis=min(n-where1,where2-1); x=where1+dis; y=where2-dis; X=x; Y=y;
                if (x==n){
                    if (y==1) next=1; else {next=2; Y--;}
                } else {next=3; X++;}
            } else {
                x=(*k1).x-1; y=(*k1).y+1; X=x; Y=y;
                if (bo[x+1][y]){
                    if (bo[x][y-1]) next=1; else next=2;
                } else if (bo[x][y-1]) next=3; else next=1;
                if (next==2) Y--; else if (next==3) X++;
            }
            C[where1+where2].push_back((line){where1,where2,x,y});
//          cout<<where1<<" "<<where2<<" "<<x<<" "<<y<<endl;
            now=next; where1=X; where2=Y; continue;
        }
    }
//  cout<<endl;
    long long ans=0;
    for (int i=1;i<=n+m;i++){
        if (C[i].size()==0) continue; //cout<<i<<endl;
        sort(C[i].begin(),C[i].end());
//      for (int j=0;j<C[i].size();j++) cout<<C[i][j].x1<<" "<<C[i][j].y1<<" "<<C[i][j].x2<<" "<<C[i][j].y2<<endl;
        int pre=C[i][0].x1,now=C[i][0].x2;
        for (int j=1;j<C[i].size();j++)
            if (C[i][j].x1>now){
                ans+=now-pre+1; pre=C[i][j].x1; now=C[i][j].x2;
            } else now=max(C[i][j].x2,now);
        ans+=now-pre+1;
//      cout<<ans<<endl;
    }
//  cout<<"over"<<endl;
    for (int i=1;i<=n+m;i++){
        if (D[i].size()==0) continue;
        sort(D[i].begin(),D[i].end());
//      for (int j=0;j<D[i].size();j++) cout<<D[i][j].x1<<" "<<D[i][j].y1<<" "<<D[i][j].x2<<" "<<D[i][j].y2<<endl;
        int pre=D[i][0].x1,now=D[i][0].x2;
        for (int j=1;j<D[i].size();j++)
            if (D[i][j].x1>now){
                ans+=now-pre+1; pre=D[i][j].x1; now=D[i][j].x2;
            } else now=max(D[i][j].x2,now);
        ans+=now-pre+1;
//      cout<<ans<<endl;
    }
/*  for (int i=0;i<d.size();i++){
        y[++len]=(atom2){d[i].x1-1,d[i].x2-1,1};
        y[++len]=(atom2){d[i].x2,d[i].x2,-1};
    }
    sort(y+1,y+len+1,compare); int now=1;
    for (int i=0;i<=n+m;i++){
        for (int j=0;j<=c[i].size();j++){
            int k1=c[i][j].x1-c[i][j].y1+m,k2=c[i][j].x2-c[i][j].y2+m;
            add(k1,1); add(k2+1,-1);
        }
        while (now<=len&&y[now].x+y[now].y==i){
            ans+=y[now].w*find(y[now].x-y[now].y+m); now++;
        }
    }*/
    cout<<ans<<endl;
    return 0;
}