#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

typedef long long LL;

const int MAXL=600000,MOD1=1000000009,MOD2=42424243;

char s[MAXL];
int pow1[MAXL]={1},pow2[MAXL]={1};
set <int> s1,s2;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<MAXL;i++)
    {
        pow1[i]=(LL)pow1[i-1]*1313%MOD1;
        pow2[i]=(LL)pow2[i-1]*4243%MOD2;
    }
    while (n--)
    {
        scanf("%s",s);
        int l=strlen(s),h1=0,h2=0;
        for (int i=0;i<l;i++)
        {
            h1=(h1+(LL)pow1[i]*s[i])%MOD1;h2=(h2+(LL)pow2[i]*s[i])%MOD2;
        }
        s1.insert(h1);s2.insert(h2);
    }
    while (m--)
    {
        scanf("%s",s);
        int l=strlen(s),h1=0,h2=0;
        bool flag=false;
        for (int i=0;i<l;i++)
        {
            h1=(h1+(LL)pow1[i]*s[i])%MOD1;h2=(h2+(LL)pow2[i]*s[i])%MOD2;
        }
        for (int i=0;i<l;i++)
        {
            for (char j='a';j<='c';j++)
                if (j!=s[i])
                {
                    int t1=(h1+(LL)(j-s[i])*pow1[i])%MOD1,t2=(h2+(LL)(j-s[i])*pow2[i])%MOD2;
                    if (t1<0) t1+=MOD1;if (t2<0) t2+=MOD2;
                    if (s1.count(t1)&&s2.count(t2))
                    {
                        flag=true;
                        break;
                    }
                }
            if (flag) break;
        }
        printf("%s\n",flag?"YES":"NO");
    }
    return 0;
}