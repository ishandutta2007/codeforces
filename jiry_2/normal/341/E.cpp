#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int x[2000],n,y[2000],c[2000000][2],m;
void sort(){
    if (x[1]>x[2]){swap(x[1],x[2]); swap(y[1],y[2]);}
    if (x[1]>x[3]){swap(x[1],x[3]); swap(y[1],y[3]);}
    if (x[2]>x[3]){swap(x[3],x[2]); swap(y[3],y[2]);}
}
void push(int k1,int k2){
    x[k2]-=x[k1]; x[k1]*=2; 
    c[++m][0]=y[k1]; c[m][1]=y[k2];
}
void push(){
    int k1=x[2]/x[1];
    for (;k1;k1>>=1) if (k1&1) push(1,2); else push(1,3);
}
int main(){
    scanf("%d",&n); m=0;
    for (int i=1;i<=n;i++){
        int k1; scanf("%d",&k1); if (k1){x[++m]=k1; y[m]=i;}
    }
    n=m; m=0; 
    if (n<2){cout<<-1<<endl; return 0;}
    for (int i=n;i>=3;i--){
        while (x[2]){sort(); push();}
        x[2]=x[i]; y[2]=y[i];
    }
    cout<<m<<endl;
    for (int i=1;i<=m;i++) printf("%d %d\n",c[i][0],c[i][1]);
    return 0;
}