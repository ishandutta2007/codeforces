#include <bits/stdc++.h>
using namespace std;
bool a[1<<20];
int b[1<<20];
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        int num=0;
        for(int j=0;j<20&&i+j<n;j++){
            if((num>>s[i+j]-'a')&1)break;
            num|=1<<s[i+j]-'a';
            a[num]=1;
            //cout<<num<<endl;
        }
    }
    for(int i=0;i<1<<20;i++)b[i]=a[i]*__builtin_popcount(i);
    for(int i=0;i<20;i++)for(int j=0;j<1<<20;j+=2<<i)for(int k=0;k<1<<i;k++)b[j+k+(1<<i)]=max(b[j+k+(1<<i)],b[j+k]);
    int ans=0;
    for(int i=0;i<1<<20;i++)ans=max(ans,a[i]*__builtin_popcount(i)+b[(1<<20)-1-i]);
    printf("%d",ans);
}