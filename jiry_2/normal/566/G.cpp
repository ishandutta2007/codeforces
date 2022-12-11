#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct point{
    int x,y;
}x[110000],y[110000];
int s[110000],n,m;
long long cross(point k1,point k2,point k3){
    return 1ll*(k1.x-k2.x)*(k1.y-k3.y)-1ll*(k1.x-k3.x)*(k1.y-k2.y);
}
int compare(point k1,point k2){
    return k1.x<k2.x;
}
int main(){
    scanf("%d%d",&n,&m); int k1,k2; scanf("%d%d",&k1,&k2);
    for (int i=1;i<=n;i++) scanf("%d%d",&y[i].x,&y[i].y);
    for (int i=1;i<=m;i++) scanf("%d%d",&x[i].x,&x[i].y);
    sort(x+1,x+m+1,compare);
    int len=1; s[1]=0;
    for (int i=1;i<=m;i++){
        while (len!=1&&cross(x[s[len-1]],x[s[len]],x[i])>0) len--;
        s[++len]=i;
    }
    for (int i=len-1;i;i--) x[s[i]].y=max(x[s[i+1]].y,x[s[i]].y);
//  for (int i=1;i<=len;i++) cout<<x[s[i]].x<<" "<<x[s[i]].y<<endl;
    sort(y+1,y+n+1,compare);
    int now=1; int flag=0;
    for (int i=1;i<=n;i++){
        while (now<=len&&x[s[now]].x<=y[i].x) now++;
    //  cout<<i<<" "<<now<<endl;
        if (now>len) {flag=1; break;}
//      cout<<cross(x[s[now-1]],x[s[now]],y[i])<<endl;
        if (cross(x[s[now-1]],x[s[now]],y[i])>=0) flag=1;
    }
    if (flag==0) cout<<"Min"<<endl; else cout<<"Max"<<endl;
    return 0;
}