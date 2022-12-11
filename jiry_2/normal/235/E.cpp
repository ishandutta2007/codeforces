#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<unordered_map>
using namespace std;
struct atom{
    int a,b,c;
    unsigned int w;
};
unordered_map<long long,int>H[600];
int n,len,a,b,c,mo=(1<<30),sign;
vector<int>prime;
int dp(int kk1,int kk2,int kk3,int kk4){
    if (kk4==-1) return 1;
    long long now=1ll*kk1*(a+1)*(a+1)+kk2*(a+1)+kk3,num=H[kk4][now];
    if (num!=0) return num; int ans=0;
    int k1=1,k2=1,k3=1,k4=0; 
//  cout<<kk1<<" "<<kk2<<" "<<kk3<<" "<<kk4<<" "<<endl;
    while (k1<=kk1){
        k2=1; int k5=0;
        while (k2<=kk2){
            k3=1; int k6=0;
            while (k3<=kk3){
                ans+=dp(kk1/k1,kk2/k2,kk3/k3,kk4-1)*(k4+k5+k6+1);
                k3=k3*prime[kk4]; k6++;
            }
            k2=k2*prime[kk4]; k5++;
        }
        k1=k1*prime[kk4]; k4++;
    }
    H[kk4][now]=ans; return ans;
}
int main(){
    scanf("%d%d%d",&a,&b,&c); 
    if (a<b) swap(a,b); if (a<c) swap(a,c);
    for (int i=2;i<=a;i++){
        int flag=0;
        for (int j=2;j<=trunc(sqrt(i));j++) if (i%j==0){flag=1; break;}
        if (flag==0) prime.push_back(i);
    }
    cout<<(dp(a,b,c,prime.size()-1)%mo+mo)%mo<<endl;
    return 0;
}