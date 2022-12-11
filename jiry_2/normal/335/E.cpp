#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
char ch[10];
int n,h;
int main(){
    scanf("%s",ch); scanf("%d%d",&n,&h);
    if (ch[0]=='B'){cout<<n<<endl; return 0;}
    long double ans=n,k1=1,k2=1,k3=1;
    for (int i=1;i<=h;i++){
        long double k4=1; k1/=4; k2/=2; k3*=2;
        for (int j=1;j<=n;j++){
            ans=ans+(n-j)*k1*k4*k3/2*(1-(j-1)/(k3-1));
            k4*=(1-k2);
        }
    }
    printf("%.11lf\n",(double)ans);
    return 0;
}