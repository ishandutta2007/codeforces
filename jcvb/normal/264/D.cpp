#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
char a[1000005];int n;
char b[1000005];int m;
int f[1000005];
int g[1000005];
vector<int> t[1000];
int main()
{
    scanf("%s",a+1);n=strlen(a+1);
    scanf("%s",b+1);m=strlen(b+1);
    a[n+1]='!';b[m+1]='?';  
    for (int i=1,j=1;i<=n;){
        f[i]=j;g[i]=m;
        if(a[i]==b[j])j++;
        i++;
    }
    for (int j=2;j<=m;j++)t[(b[j-1]-'A')*26+b[j]-'A'].push_back(j);
    for (int j=1,i=1;j<=m;){
        g[i]=j;
        if(a[i]==b[j])i++;
        j++;
    }
    ll ans=0;
    for (int i=1;i<=n;i++){
        ans+=g[i]-f[i]+1;
        if(i>1 && a[i]!=a[i-1]){
            int tmp=(a[i]-'A')*26+a[i-1]-'A';
            ans-=upper_bound(t[tmp].begin(),t[tmp].end(),g[i])-lower_bound(t[tmp].begin(),t[tmp].end(),f[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}