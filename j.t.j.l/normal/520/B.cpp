#include<iostream>
#include<cmath> 
#include<cstdio>
#include<algorithm>
//#include <queue>
#define N 400005
#define MM 1000000009
#define INF 0x4fffffff
#define PI 3.14159265358979323846

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)

using namespace std;

int n,m,i,h,t,x,f[20000],q[20000];

int main(){
    cin>>n>>m;
    if (n>=m)
        cout<<n-m<<endl;
    else{
        rep(i,1,2*m)
            f[i]=INF;
        h=0;
        t=1;
        q[1]=n;
        f[n]=0;
        while (h<t){
            h++;
            x=q[h];
            if ((x*2<=2*m)&&(f[2*x]>f[x]+1)){
                t++;
                q[t]=x*2;
                f[2*x]=f[x]+1;
            }
            if ((x>1)&&(f[x-1]>f[x]+1)){
                t++;
                q[t]=x-1;
                f[x-1]=f[x]+1;
            }
        }
        cout<<f[m]<<endl;
    }
    return 0;
}