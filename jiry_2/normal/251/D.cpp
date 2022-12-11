#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct atom{
    int x[110000],fir;
}A[130],now;
int n,len,a[110000],ans[110000];
long long x[110000],two[70];
void addin(){
    for (int i=1;i<=n;i++)
        if (now.x[i]){
            int where=0;
            for (int j=1;j<=len;j++) if (A[j].fir==i) where=j;
            if (where==0) break;
            for (int j=0;j<=n;j++) now.x[j]^=A[where].x[j];
        }
    int where=0;
    for (int i=1;i<=n;i++) if (now.x[i]){where=i; break;}
    if (where){A[++len]=now; A[len].fir=where;}
}
void find(int k){
    if (k==0) return;
    if (a[k]==0){ans[k]=0; find(k-1); return;}
    for (int i=k+1;i<=n;i++) if (A[a[k]].x[i]) A[a[k]].x[0]^=ans[i]; ans[k]=A[a[k]].x[0]; find(k-1);
}
int main(){
    scanf("%d",&n); for (int i=1;i<=n;i++) scanf("%I64d",&x[i]);
    two[0]=1;
    for (int i=1;i<60;i++) two[i]=two[i-1]*2;
    for (int i=59;i>=0;i--){
        memset(now.x,0x00,sizeof now.x);
        int num=0;
        for (int j=1;j<=n;j++) if (x[j]&two[i]){num++; now.x[j]=1;}
        if (num%2) continue; now.x[0]=1; addin();
    }
/*  for (int i=1;i<=len;i++){
        for (int j=0;j<=n;j++) cout<<A[i].x[j]<<" "; cout<<A[i].fir<<endl;
    }
    cout<<endl;*/
    for (int i=59;i>=0;i--){
        memset(now.x,0x00,sizeof now.x);
        int num=0;
        for (int j=1;j<=n;j++) if (x[j]&two[i]){num++; now.x[j]=1;} //cout<<i<<" "<<num<<" "<<two[i]<<endl; 
        now.x[0]=num%2; addin();
    }
/*  for (int i=1;i<=len;i++){
        for (int j=0;j<=n;j++) cout<<A[i].x[j]<<" "; cout<<A[i].fir<<endl;
    }*/
    for (int i=1;i<=len;i++) a[A[i].fir]=i;
    find(n);
    for (int i=1;i<=n;i++) printf("%d ",ans[i]+1); cout<<endl; return 0;
}