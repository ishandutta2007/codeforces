#include<bits/stdc++.h>
using namespace std;
const int mn=4e5+10;
int a[mn],ra[mn],l[mn],r[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i),ra[a[i]]=i;
    stack<int>s;
    s.push(0);
    a[0]=a[n+1]=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        while(a[s.top()]<=a[i])s.pop();
        l[i]=s.top()+1;
        s.push(i);
    }
    while(s.size())s.pop();
    s.push(n+1);
    for(int i=n;i>=1;i--){
        while(a[s.top()]<=a[i])s.pop();
        r[i]=s.top()-1;
        s.push(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i-l[i]<r[i]-i){
            for(int j=l[i];j<i;j++)if(ra[a[i]-a[j]]>i&&ra[a[i]-a[j]]<=r[i])ans++;
        }
        else{
            for(int j=i+1;j<=r[i];j++)if(ra[a[i]-a[j]]<i&&ra[a[i]-a[j]]>=l[i])ans++;
        }
    }
    printf("%d",ans);
}