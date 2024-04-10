#include<iostream>
#include<cmath> 
#include<cstdio>
#include<algorithm>
#define N 305
#define INF 0x4fffffff
#define PI 3.14159265358979323846

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)

using namespace std;

long long A,B,T,o;
int t,l,m,L,R,M;

int main(){
    cin>>A>>B>>T;
    rep(o,1,T){
        scanf("%d %d %d",&l,&t,&m);
        if (A+(l-1)*B>t)
            printf("-1\n");
        else{
            L=l;
            R=(t-A)/B+2;
            while (L+1<R){
                M=(L+R)>>1;
                if ((M-l+1)*A+B*(l+M-2)*(M-l+1)/2<=(long long)m*t)
                    L=M;
                else
                    R=M;                
            }
            printf("%d\n",L);
        }
    }
    return 0;
}