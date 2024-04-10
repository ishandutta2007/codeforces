// Hydro submission #62d29be1b36e4a12382afb46@1657969634243
#include<bits/stdc++.h>
using namespace std;
int a[200001],b[10];
map<int,bool> mp;
int main()
{
    int t,n,s,s1,s2,i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n;s1=0,s2=0;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]<0) s1++;
            if(a[i]>0) s2++;
        }
        if(s1>2||s2>2)
        printf("NO\n");
        else
        {
            bool f=true;
            s=0,mp.clear();
            sort(a+1,a+n+1);
            for(i=1;i<=n;i++)
            if(a[i])
            {
                b[++s]=a[i];
                mp[a[i]]=true;
            }
            else if(f)
            {
                b[++s]=0;
                mp[0]=true;
                f=false;
            }
            for(i=1;i<s-1;i++)
            for(j=i+1;j<s;j++)
            for(k=j+1;k<=s;k++)
            if(!mp[b[i]+b[j]+b[k]])
            {
                printf("NO\n");
                goto next;
            }
            printf("YES\n");
            next:;
        }
    }
    return 0;
}