#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=1e5+10;
int k[mn];
int main(){
    int n;
    vector<int>a,b;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",k+i),k[i]+=k[i-1];
    for(int i=1;i<=n;i++){
        if(k[i]*3==k[n])a.push_back(i);
        if(k[i]*3==k[n]*2&&i!=n)b.push_back(i);
    }
    ll ans=0;
    for(int i=0,j=0;i<b.size();i++){
        while(j<a.size()&&a[j]<b[i])j++;
        ans+=j;
    }
    printf("%lld",ans);
}