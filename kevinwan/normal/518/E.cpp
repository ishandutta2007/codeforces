#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=3e5+10;
const int inf=0x3f3f3f3f;
int a[mn];
void die(){
    printf("Incorrect sequence");
    exit(0);
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=k;i<n+k;i++){
        string s;
        cin>>s;
        if(s=="?")a[i]=inf;
        else a[i]=stoi(s);
    }
    for(int i=0;i<k;i++)a[i]=0xc0c0c0c0;
    for(int i=n+k;i<n+2*k;i++)a[i]=0x3f3f3f3e;
    for(int i=0;i<k;i++){
        int lv=i;
        for(int j=i+k;j<n+2*k;j+=k){
            if(a[j]!=inf){
                if(a[j]-a[lv]<(j-lv)/k)die();
                int len=(j-lv)/k-1;
                int lo=a[lv]+1,hi=a[j]-len;
                int bes2=-len+1;
                int u=0;
                if(lo<=bes2/2&&bes2/2<=hi)u=bes2/2;
                else if(abs(bes2-2LL*lo)<abs(bes2-2LL*hi))u=lo;
                else u=hi;
                for(int l=lv+k;l<j;l+=k)a[l]=u++;
                lv=j;
            }
        }
    }
    for(int i=k;i<n+k;i++)printf("%d ",a[i]);
}