#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
struct point{
    int x,y;
    void scan(){
        scanf("%d%d",&x,&y); x+=150; y+=150;
    }
}x[500],s,t;
queue<point>Q;
int m,pd[401][401],gox[4]={0,1,0,-1},goy[4]={1,0,-1,0},n,d[401][401],flag;
vector<int>ans;
void print(int k){
    k--;
    if (k==0) putchar('U'); else if (k==1) putchar('R'); else if (k==2) putchar('D'); else putchar('L');
}
int check(int k1,int k2){
    if (k1<0||k1>n||k2<0||k2>n) return 0;
    return pd[k1][k2];
}
void firstgo(){
    while (1){
//      cout<<s.x<<" "<<s.y<<" "<<t.x<<" "<<t.y<<endl;
        memset(d,0x00,sizeof d);
        point tt=(point){min(n,max(0,t.x)),min(n,max(0,t.y))};
        Q.push(tt); d[tt.x][tt.y]=1; d[tt.x][tt.y]=1;
        while (!Q.empty()){
            point k=Q.front();
            for (int i=0;i<4;i++){
                point k1=(point){k.x+gox[i],k.y+goy[i]};
                if (k1.x>=0&&k1.x<=n&&k1.y>=0&&k1.y<=n&&pd[k1.x][k1.y]==0&&d[k1.x][k1.y]==0){
                    Q.push(k1); d[k1.x][k1.y]=d[k.x][k.y]+1;
                }
            }
            Q.pop();
        }
//      cout<<d[s.x][s.y]<<" "; int kkk; cin>>kkk;
        if (d[s.x][s.y]==0){flag=1; cout<<-1<<endl; return;}
        while (s.x!=tt.x||s.y!=tt.y)
            for (int i=0;i<4;i++){
            //  cout<<d[s.x+gox[i]][s.y+goy[i]]<<" "<<d[s.x][s.y]<<endl;
                if (d[s.x+gox[i]][s.y+goy[i]]==d[s.x][s.y]-1){
                    s.x+=gox[i]; s.y+=goy[i]; ans.push_back(i+1);
                    if (check(t.x+gox[i],t.y+goy[i])==0){
                        t.x+=gox[i]; t.y+=goy[i];
                    }
                    break;
                }
            }
        if (s.x<50||s.x>250||s.y<50||s.y>250) return;
        if (s.x==t.x&&s.y==t.y){
            for (int i=0;i<ans.size();i++) print(ans[i]); cout<<endl; flag=1; return;
        }
    }
}
point findup(){
    int now=-100; point ans;
    for (int i=1;i<=m;i++) if (x[i].y>now){ans=x[i]; now=x[i].y;}
    return ans;
}
point finddown(){
    int now=1000; point ans;
    for (int i=1;i<=m;i++) if (x[i].y<now){ans=x[i]; now=x[i].y;}
    return ans;
}
point findright(){
    int now=-100; point ans;
    for (int i=1;i<=m;i++) if (x[i].x>now){ans=x[i]; now=x[i].x;}
    return ans;
}
point findleft(){
    int now=1000; point ans;
    for (int i=1;i<=m;i++) if (x[i].x<now){ans=x[i]; now=x[i].x;}
    return ans;
}
int main(){
    s.scan(); t.scan(); scanf("%d",&m); n=300;
    for (int i=1;i<=m;i++) x[i].scan();
    for (int i=1;i<=m;i++) pd[x[i].x][x[i].y]=1; flag=0;
    firstgo(); if (flag) return 0;
    if (m==0){cout<<-1<<endl; return 0;}
    if (s.x<t.x){
        point k1=findleft();
        if (k1.x<=t.x){
            if (s.y>=150)
                for (int i=1;i<=500;i++){
                    s.y++; t.y++; ans.push_back(1);
                }
            else 
                for (int i=1;i<=500;i++){
                    s.y--; t.y--; ans.push_back(3);
                }
            while (t.x!=k1.x-1){
                s.x--; t.x--; ans.push_back(4);
            }
        } else 
            while (t.x!=k1.x-1){
                s.x++; t.x++; ans.push_back(2);
            }
        while (t.y!=k1.y){
            if (t.y<k1.y){
                ans.push_back(1); s.y++; t.y++;
            }
            if (t.y>k1.y){
                ans.push_back(3); s.y--; t.y--;
            }
        }
        while (s.x<t.x){
            s.x++; ans.push_back(2);
        }
        if (s.y<t.y){
            point k2=finddown();
            while (t.y!=k2.y-1){
                s.y--; t.y--; ans.push_back(3);
            }
            while (t.x!=k2.x){
                t.x++; s.x++; ans.push_back(2);
            }
            while (s.y!=t.y){
                s.y++; ans.push_back(1);
            }
        } else {
            point k2=findup();
            while (t.y!=k2.y+1){
                s.y++; t.y++; ans.push_back(1);
            }
            while (t.x!=k2.x){
                t.x++; s.x++; ans.push_back(2);
            }
            while (s.y!=t.y){
                s.y--; ans.push_back(3);
            }
        }
    } else {
        point k1=findright();
        if (k1.x>=t.x){
            if (s.y>=150)
                for (int i=1;i<=500;i++){
                    s.y++; t.y++; ans.push_back(1);
                }
            else 
                for (int i=1;i<=500;i++){
                    s.y--; t.y--; ans.push_back(3);
                }
            while (t.x!=k1.x+1){
                s.x++; t.x++; ans.push_back(2);
            }
        } else 
            while (t.x!=k1.x+1){
                s.x--; t.x--; ans.push_back(4);
            }
        while (t.y!=k1.y){
            if (t.y<k1.y){
                ans.push_back(1); s.y++; t.y++;
            }
            if (t.y>k1.y){
                ans.push_back(3); s.y--; t.y--;
            }
        }
        while (s.x>t.x){
            s.x--; ans.push_back(4);
        }
        if (s.y<t.y){
            point k2=finddown();
            while (t.y!=k2.y-1){
                s.y--; t.y--; ans.push_back(3);
            }
            while (t.x!=k2.x){
                t.x--; s.x--; ans.push_back(4);
            }
            while (s.y!=t.y){
                s.y++; ans.push_back(1);
            }
        } else {
            point k2=findup();
            while (t.y!=k2.y+1){
                s.y++; t.y++; ans.push_back(1);
            }
            while (t.x!=k2.x){
                t.x--; s.x--; ans.push_back(4);
            }
            while (s.y!=t.y){
                s.y--; ans.push_back(3);
            }
        }
    }
    for (int i=0;i<ans.size();i++) print(ans[i]); cout<<endl; return 0;
}