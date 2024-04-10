#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int a[11000],b[110000],mo,g,n,m,num,c[11000],w[11000],pd[11000];
vector<int>A;
int quick(int k1,int k2){
    int k3=1;
    while (k2){
        if (k2&1) k3=1ll*k3*k1%mo; k1=1ll*k1*k1%mo; k2=k2/2;
    }
    return k3;
}
int gcd(int k1,int k2){
    if (k2==0) return k1; return gcd(k2,k1%k2);
}
int main(){
    scanf("%d%d%d",&n,&m,&mo);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=m;i++) scanf("%d",&b[i]); num=mo-1;
    for (int i=1;i<=m;i++) num=gcd(num,b[i]);
    for (int i=1;i<=trunc(sqrt(mo-1));i++)
        if ((mo-1)%i==0){
            A.push_back(i); if (i*i!=mo-1) A.push_back((mo-1)/i);
        }
    sort(A.begin(),A.end());
    for (int i=1;i<=n;i++)
        for (int j=0;j<A.size();j++) if (quick(a[i],A[j])==1){c[i]=(mo-1)/A[j]; break;} //cout<<c[1]<<endl;
    mo=(mo-1)/num; for (int i=1;i<=n;i++) c[i]=gcd(c[i],mo);
    A.clear(); int ans=0;
    for (int i=1;i<=trunc(sqrt(mo));i++)
        if (mo%i==0){
            A.push_back(i); if (i*i!=mo) A.push_back(mo/i);
        }
    sort(A.begin(),A.end());
    for (int i=1;i<=n;i++) pd[lower_bound(A.begin(),A.end(),c[i])-A.begin()]=1;
    for (int i=0;i<A.size();i++) if (pd[i]){
        for (int j=A.size()-1;j>=0;j--) w[lower_bound(A.begin(),A.end(),1ll*A[i]*A[j]/gcd(A[i],A[j]))-A.begin()]-=w[j];
        w[i]++;
    }
//  for (int i=0;i<A.size();i++) cout<<A[i]<<" "<<w[i]<<endl;
    for (int i=0;i<A.size();i++) ans+=1ll*mo/A[i]*w[i];
    cout<<ans<<endl; return 0;
}