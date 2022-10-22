#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=3e5+10;
ll po(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
int num[mn];
int wor[mn],wor2[mn];
int main(){
    memset(wor,0x3f,sizeof(wor));
    memset(wor2,0x3f,sizeof(wor2));
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        for(int j=2;j*j<=a;j++){
            if(a%j==0){
                int ct=0;
                while(a%j==0){
                    ct++;
                    a/=j;
                }
                num[j]++;
                if(ct<wor[j])wor2[j]=wor[j],wor[j]=ct;
                else if(ct<wor2[j])wor2[j]=ct;
            }
        }
        if(a!=1){
            num[a]++;
            if(1<wor[a])wor2[a]=wor[a],wor[a]=1;
            else if(1<wor2[a])wor2[a]=1;
        }
    }
    ll ans=1;
    for(int i=2;i<mn;i++){
        if(num[i]==n-1)ans*=po(i,wor[i]);
        else if(num[i]==n)ans*=po(i,wor2[i]);
    }
    printf("%lld",ans);
}