#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=3e5+10;
int a[mn];
int l[mn],r[mn],lb[mn],rb[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    stack<int>s;
    a[0]=a[n+1]=0x3f3f3f3f;
    s.push(0);
    for(int i=1;i<=n;i++){
        while(a[i]>a[s.top()])s.pop();
        l[i]=s.top();
        s.push(i);
    }
    while(s.size())s.pop();
    s.push(n+1);
    for(int i=n;i>=1;i--){
        while(a[i]>=a[s.top()])s.pop();
        r[i]=s.top();
        s.push(i);
    }
    for(int i=1;i<=n;i++)lb[i]=l[i],rb[i]=r[i];
    for(int i=0;i<30;i++){
        int l1=0;
        for(int j=1;j<=n;j++){
            if(!((a[j]>>i)&1))lb[j]=max(lb[j],l1);
            else l1=j;
        }
        l1=n+1;
        for(int j=n;j>=1;j--){
            if(!((a[j]>>i)&1))rb[j]=min(rb[j],l1);
            else l1=j;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=1LL*(i-l[i])*(r[i]-i)-1LL*(i-lb[i])*(rb[i]-i);
    }
    printf("%lld",ans);
}