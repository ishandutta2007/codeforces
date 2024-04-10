#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<time.h>
using namespace std;
const int maxn=1e5+5,maxm=20;
char s[maxn];
int c[maxm][maxm],sc[maxm];
int num[1<<20];
int f[1<<20];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int n,m;
    n=read();m=read();
    scanf("%s",s+1);
    double t=clock()*1.0/CLOCKS_PER_SEC;
    for(int i=2;i<=n;i++){
        int x=s[i-1]-'a',y=s[i]-'a';
        if(x>y)swap(x,y);
        if(x^y){
            c[x][y]++;
            sc[x]++;sc[y]++;
        }
    }
//    cout<<sc[0]<<" "<<sc[1]<<" "<<sc[2]<<endl;
    int S=(1<<m);
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int s=1;s<S;s++){
        num[s]=num[s>>1]+(s&1);
        for(int i=0;i<m;i++){
            if(!(s&(1<<i)))continue;
            int sum=0;
            for(int j=0;j<m;j++){
                if((!(s&(1<<j)))||i==j)continue;
                if(i<j)sum+=c[i][j];
                else sum+=c[j][i];
            }
            int t=s^(1<<i);
            f[s]=min(f[s],f[t]+num[s]*(sum-(sc[i]-sum)));
        }
//        cout<<s<<" "<<f[s]<<endl;
    }
    printf("%d\n",f[S-1]);
//    cerr<<clock()*1.0/CLOCKS_PER_SEC-t<<endl;
    return 0;
}