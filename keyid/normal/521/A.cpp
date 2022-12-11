#include <cstdio>

const int MAXL=100005,MOD=1000000007;
const char alpha[5]={"ACGT"};

char s[MAXL];
int cnt[100],al[MAXL];

int main()
{
    int l;
    scanf("%d%s",&l,s);
    for (int i=0;i<l;i++) cnt[s[i]]++;
    int ch=0;
    for (int i=0,_max=0;i<4;i++)
        if (cnt[alpha[i]]>_max)
        {
            _max=cnt[alpha[i]];
            ch=1;
        }
        else if (cnt[alpha[i]]==_max) ch++;
    int ans=1;
    for (int i=0;i<l;i++) ans=(long long)ans*ch%MOD;
    printf("%d",ans);
    return 0;
}