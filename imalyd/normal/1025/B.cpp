//Problem B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[150005],b[150005];
int dv(int a,int b){return !(b%a);}
int chk(int v){
    for(int i=1;i<n;i++)if(!(dv(v,a[i])||dv(v,b[i])))return 0;
    return 1;
}
int cal(int v){
    int u=sqrt(v);
    for(int i=2;i<=u;i++)if(!(v%i)){
        if(chk(i))return i;
        while(!(v%i))v/=i;
    }
    if(v!=1&&chk(v))return v;
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%d",&a[i],&b[i]);
    int v=cal(a[0]);
    if(v)printf("%d",v);
    else{
        v=cal(b[0]);
        if(v)printf("%d",v);
        else printf("-1");
    }
    return 0;
}