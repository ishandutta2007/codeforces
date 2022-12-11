#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
map<int,int>A[110000];
int n,m,now,gox,goy,k1,k2;
char ch[10];
int main(){
    scanf("%d%d",&n,&m); scanf("%d%d",&k1,&k2); scanf("%s",ch+1);
    gox=1; goy=1; if (ch[1]=='U') gox=-1; if (ch[2]=='L') goy=-1;
    int rem=n+m-2,ti=0; long long ans=1;
    if (k1==1||k1==n||k2==1||k2==m){A[k1][k2]=1; rem--;}
    while (1){
   //   cout<<k1<<" "<<k2<<" "<<rem<<" "<<ans<<endl;
        ti++; if (ti>=500000){cout<<-1<<endl; return 0;} int dis=1e9;
        if (gox==1) dis=min(dis,n-k1); else dis=min(dis,k1-1);
        if (goy==1) dis=min(dis,m-k2); else dis=min(dis,k2-1);
        k1+=gox*dis; k2+=goy*dis; ans+=dis;
        if (k1==1) gox=1; if (k1==n) gox=-1;
        if (k2==1) goy=1; if (k2==m) goy=-1;
        if (A[k1][k2]==0){rem--; A[k1][k2]=1;} if (rem==0){cout<<ans<<endl; return 0;}
    }
    return 0;
}