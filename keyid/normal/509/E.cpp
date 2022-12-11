#include <cstdio>
#include <cstring>

const int MAXL=500000+5;

char s[MAXL];
bool v[100];
double a[MAXL],b[MAXL];

int main()
{
    v['I']=v['E']=v['A']=v['O']=v['U']=v['Y']=true;
    scanf("%s",s);
    int l=strlen(s);
    for (int i=l;i>=1;i--) a[i]=a[i+1]+1.0/i;
    b[1]=a[1];
    for (int i=2;i<=l;i++)
    {
        b[i]=b[i-1]+a[i]-a[l-i+2];
    }
    double ans=0;
    for (int i=0;i<l;i++)
        if (v[s[i]])
        {
            ans+=b[i+1];
        }
    printf("%.7f",ans);
    return 0;
}