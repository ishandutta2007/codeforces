#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
typedef long long ll;
const int mn=2e5+10;
int a[60][60];
int n;
void report(bool rev){
    if(rev){
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if((i+j)&1)a[i][j]^=1;
    }
    printf("!\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)printf("%d",a[i][j]);
        printf("\n");
    }
    fflush(stdout);
    exit(0);
}
int ask(int r1,int c1,int r2,int c2){
    printf("? %d %d %d %d\n",r1,c1,r2,c2);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x;
}
int main(){
    scanf("%d",&n);
    a[1][1]=1;
    for(int i=3;i<=n;i+=2)a[1][i]=a[1][i-2]^ask(1,i-2,1,i)^1;
    for(int i=3;i<=n;i+=2)for(int j=1;j<=n;j+=2)if(i!=n||j!=n)a[i][j]=a[i-2][j]^ask(i-2,j,i,j)^1;
    for(int i=2;i<=n;i+=2)for(int j=2;j<=n;j+=2)a[i][j]=a[i-1][j-1]^ask(i-1,j-1,i,j)^1;

    for(int i=4;i<=n;i+=2)a[1][i]=a[1][i-2]^ask(1,i-2,1,i)^1;
    for(int i=3;i<=n;i+=2)for(int j=2;j<=n;j+=2)a[i][j]=a[i-2][j]^ask(i-2,j,i,j)^1;
    a[n-1][1]=a[n][2]^ask(n-1,1,n,2)^1;
    for(int i=3;i<=n;i+=2)a[n-1][i]=a[n-1][i-2]^ask(n-1,i-2,n-1,i)^1;
    for(int i=n-3;i>=1;i-=2)for(int j=1;j<=n;j+=2)a[i][j]=a[i+2][j]^ask(i,j,i+2,j)^1;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i+1<=n&&j-1>=1){
        if(a[i+1][j-1]!=a[i][j]){
            int b,c,d,e;
            if(i+2<=n)b=i,c=j-1,d=i+2,e=j;
            else if(i+1<=n&&j+1<=n)b=i,c=j-1,d=i+1,e=j+1;
            else if(j-2>=1)b=i,c=j-2,d=i+1,e=j;
            else if(i-1>=1&&j-1>=1)b=i-1,c=i-1,d=i+1,e=j;
            else assert(0);
            report(a[b][c]^a[d][e]^ask(b,c,d,e)^1);
        }
    }
    for(int i=1;i+2<=n;i++){
        if(a[i][i]==a[i+1][i+1]&&a[i+1][i+1]!=a[i+2][i+2]){
            if(a[i][i+1]==a[i+1][i+2])report(a[i][i]^a[i+1][i+2]^ask(i,i,i+1,i+2)^1);
            else report(a[i][i+1]^a[i+2][i+2]^ask(i,i+1,i+2,i+2)^1);
        }
        else if(a[i][i]!=a[i+1][i+1]&&a[i+1][i+1]==a[i+2][i+2]){
            if(a[i][i+1]!=a[i+1][i+2])report(a[i][i]^a[i+1][i+2]^ask(i,i,i+1,i+2)^1);
            else report(a[i][i+1]^a[i+2][i+2]^ask(i,i+1,i+2,i+2)^1);
        }
    }
    assert(0);
}