#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int a[3010][3010],b[3010][3010],c[3010][3010],d[3010][3010],e[3010][3010],l[100100],u[100100];
int n;
struct atom{
    int x1,y1,x2,y2;
}x[100100];
struct atom2{
    int w,where;
};
int operator < (atom2 k1,atom2 k2){
    return k1.w<k2.w;
}
set<atom2>s[3005];
int check(int k1,int k2,int k3,int k4){
//  cout<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<endl;
    if (a[k3][k4]+a[k1][k2]-a[k1][k4]-a[k3][k2]!=(k3-k1)*(k4-k2)) return 2;
    if ((b[k1+1][k4]-b[k1+1][k2])<(k4-k2)||(d[k3][k4]-d[k3][k2])<(k4-k2)) return 0;
    if ((c[k3][k2+1]-c[k1][k2+1])<(k3-k1)||(e[k3][k4]-e[k1][k4])<(k3-k1)) return 0;
    return 1;
}
void print(int k1,int k2,int k3,int k4){
    cout<<"YES "; int ans=0;
    for (int i=1;i<=n;i++) if (x[i].x1>=k1&&x[i].x2<=k3&&x[i].y1>=k2&&x[i].y2<=k4) ans++; cout<<ans<<endl;
    for (int i=1;i<=n;i++) if (x[i].x1>=k1&&x[i].x2<=k3&&x[i].y1>=k2&&x[i].y2<=k4) printf("%d ",i); cout<<endl;
}
int main(){
    scanf("%d",&n); 
    for (int i=1;i<=n;i++) scanf("%d%d%d%d",&x[i].x1,&x[i].y1,&x[i].x2,&x[i].y2);
    for (int i=1;i<=n;i++){
        a[x[i].x1+1][x[i].y1+1]++; a[x[i].x1+1][x[i].y2+1]--; a[x[i].x2+1][x[i].y1+1]--; a[x[i].x2+1][x[i].y2+1]++;
        b[x[i].x1+1][x[i].y1+1]++; b[x[i].x1+1][x[i].y2+1]--; d[x[i].x2][x[i].y1+1]++; d[x[i].x2][x[i].y2+1]--;
        c[x[i].x1+1][x[i].y1+1]++; c[x[i].x2+1][x[i].y1+1]--; e[x[i].x1+1][x[i].y2]++; e[x[i].x2+1][x[i].y2]--;
    }
    for (int i=1;i<=3005;i++)
        for (int j=1;j<=3005;j++){
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            b[i][j]+=b[i][j-1]; c[i][j]+=c[i-1][j];
            d[i][j]+=d[i][j-1]; e[i][j]+=e[i-1][j];
        }   
    for (int i=1;i<=3005;i++)
        for (int j=1;j<=3005;j++){
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            b[i][j]+=b[i][j-1]; c[i][j]+=c[i-1][j];
            d[i][j]+=d[i][j-1]; e[i][j]+=e[i-1][j];
        }
    for (int i=1;i<=n;i++) s[x[i].y1].insert((atom2){x[i].x2,i});
    for (int i=1;i<=n;i++){
        set<atom2>::iterator k1=s[x[i].y1].find((atom2){x[i].x1,0});
        if (k1==s[x[i].y1].end()) continue; l[i]=(*k1).where;
    }
    for (int i=0;i<=3004;i++) s[i].clear();
    for (int i=1;i<=n;i++) s[x[i].x2].insert((atom2){x[i].y1,i});
    for (int i=1;i<=n;i++){
        set<atom2>::iterator k1=s[x[i].x2].find((atom2){x[i].y2,0});
        if (k1==s[x[i].x2].end()) continue; u[i]=(*k1).where;
    }
    //for (int i=1;i<=n;i++) cout<<l[i]<<" "<<u[i]<<endl;
    for (int i=1;i<=n;i++){
        int k1=i,k2=i,k3=x[i].x1,k4=x[i].y2;
        while (1){
        //  cout<<i<<" "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<l[k1]<<" "<<u[k2]<<endl;
            int len=min(x[i].x2-k3,k4-x[i].y1),k5=check(x[i].x2-len,x[i].y1,x[i].x2,x[i].y1+len);
            if (k5==2) break; 
            if (k5==1){print(x[i].x2-len,x[i].y1,x[i].x2,x[i].y1+len); return 0;}
            if (x[i].x2-k3<k4-x[i].y1){
                if (l[k1]==0) break; k1=l[k1]; k3=x[k1].x1;
            } else if (x[i].x2-k3>k4-x[i].y1){
                if (u[k2]==0) break; k2=u[k2]; k4=x[k2].y2;
            } else {
                if (u[k2]==0) break; k2=u[k2]; k4=x[k2].y2;
                if (l[k1]==0) break; k1=l[k1]; k3=x[k1].x1;
            }
        }
    }
    cout<<"NO"<<endl; return 0;
}