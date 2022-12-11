#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

typedef long long LL;

const int MAXL=100005;

char s[MAXL];
int a[26],last[26];
LL sum[MAXL];
map <LL,int> ms[26];

int main()
{
    for (int i=0;i<26;i++) scanf("%d",&a[i]);
    scanf("%s",s+1);
    int l=strlen(s+1);
    LL ans=0;
    for (int i=1;i<=l;i++)
    {
        int c=s[i]-'a';
        sum[i]=sum[i-1]+a[c];
        LL x=sum[i-1]-a[c];
        if (ms[c].count(x)) ans+=ms[c][x];
        if (ms[c].count(sum[i-1])) ms[c][sum[i-1]]++;else ms[c][sum[i-1]]=1;
    }
    printf("%I64d",ans);
    return 0;
}