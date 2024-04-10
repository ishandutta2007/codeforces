#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char s[N];
struct node
{
    int l,a[N];
    node(){memset(a,0,sizeof(a));}
}x;
int n;
node getlater(node o,int p)
{
    int l=0;
    node ans;
    for(int i=p;i<=o.l;i++)
        ans.a[++l]=o.a[i];
    ans.l=l;
    return ans;
}
node Min(node a,node b)
{
    if(a.l==b.l)
    {
        for(int i=1;i<=a.l;i++)
            if(a.a[i]!=b.a[i])
                    return a.a[i]<b.a[i]?a:b;
        return a;
    }
    return a.l<b.l?a:b;
}
node add(node a,node b)
{
        node ans;
        int i=a.l,j=b.l,len=0;
        while(i>=1&&j>=1)
        {
            ++len;
            ans.a[len]+=a.a[i]+b.a[j];
            ans.a[len+1]+=ans.a[len]/10;
            ans.a[len]%=10;
            i--;j--;
        }
        while(j>=1)
        {
            ++len;
            ans.a[len]+=b.a[j];
            ans.a[len+1]+=ans.a[len]/10;
            ans.a[len]%=10;
            j--;
        }
        while(i>=1)
        {
            ++len;
            ans.a[len]+=a.a[i];
            ans.a[len+1]+=ans.a[len]/10;
            ans.a[len]%=10;
            i--;
        }
        if(ans.a[len+1]) len++;
        reverse(ans.a+1,ans.a+1+len);
        ans.l=len;
        return ans;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
        x.a[i]=s[i]-'0';
    x.l=n;
    int l=n/2,r=n/2;
    while(x.a[l]==0) l--;
    while(x.a[r]==0&&r<=x.l) r++;
    node ans;
    for(int i=1;i<=n;i++)
        ans.a[i]=9;
    ans.l=n;
    int t=5;
    while(t&&l>1)
    {
        if(x.a[l]) t--;
        else {l--;continue;}
        node y=x;y.l=l-1;
        ans=Min(ans,add(y,getlater(x,l)));
        l--;
    }
    t=5;
    while(t&&r<=n)
    {
        if(x.a[r]) t--;
        else {r++;continue;};
        node y=x;y.l=r-1;
        ans=Min(ans,add(y,getlater(x,r)));
        r++;
    }
    for(int i=1;i<=ans.l;i++)
        printf("%d",ans.a[i]);
}