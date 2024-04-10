#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x[2000],z[4][2],len,flag,a[2000];
void reverse(int l,int r){
    while (l<r){
        swap(x[l],x[r]); l++; r--;
    }
}
void solve(int k){
    int pd=0;
    for (int i=1;i<=n;i++) if (x[i]!=i){pd=1; break;}
    if (pd==0){
        cout<<k<<endl;
        for (int i=k;i;i--) cout<<z[i][0]<<" "<<z[i][1]<<endl;
        flag=1; return;
    }
    if (k==3) return;
    int y[30],len=0;
    for (int i=1;i<=n;i++) if (abs(x[i]-x[i-1])>1||abs(x[i+1]-x[i])>1) y[++len]=i;
    for (int i=1;i<=len;i++)
        for (int j=i+1;j<=len;j++){
            z[k+1][0]=y[i]; z[k+1][1]=y[j];
            reverse(y[i],y[j]); solve(k+1);
            reverse(y[i],y[j]); if (flag) return;
        }
}
int main(){
    scanf("%d",&n); for (int i=1;i<=n;i++) scanf("%d",&x[i]); x[0]=0; x[n+1]=n+1;
    solve(0); return 0;
}