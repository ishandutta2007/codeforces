#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct point{
    long long x,y;
}x[110000];
int n,k1,k2,a,b,c,d,y[110000],where,f[110000],A[110000];
int getin(){
    char ch=getchar(); while (ch<'0'||ch>'9') ch=getchar();
    int num=0; while (ch>='0'&&ch<='9'){num=num*10+ch-'0'; ch=getchar();} return num;
}
int compare(int k1,int k2){
    return x[k1].y>x[k2].y;
}
int compare2(point k1,point k2){
    return k1.x>k2.x||(k1.x==k2.x&&k1.y<k2.y);
}
int find(int k){
    int num=0; for (;k;k-=k&(-k)) num=max(num,A[k]); return num;
}
void add(int k1,int k2){
    for (;k1<=n;k1+=k1&(-k1)) A[k1]=max(A[k1],k2);
}
int main(){
    scanf("%d",&n); a=getin(); b=getin(); c=getin(); d=getin();
    for (int i=1;i<=n;i++){
        int k1,k2; scanf("%d%d",&k1,&k2); x[i]=(point){1ll*c*k1-1ll*d*k2,1ll*b*k2-1ll*a*k1};
    }
    x[++n]=(point){0,0}; sort(x+1,x+n+1,compare2);
    for (int i=1;i<=n;i++) if (x[i].x==0&&x[i].y==0){where=i; break;}
    for (int i=1;i<=n;i++) y[i]=i; sort(y+1,y+n+1,compare);
    int now=1; long long pre=x[y[1]].y; x[y[1]].y=1; //cout<<where<<endl; 
    for (int i=2;i<=n;i++){
        if (x[y[i]].y!=pre) {pre=x[y[i]].y; now++;} x[y[i]].y=now;
    }
    for (int i=1;i<=n;i++){
        f[i]=find(x[i].y-1)+1; add(x[i].y,f[i]); 
    }
    cout<<f[where]-1<<endl; return 0;
}