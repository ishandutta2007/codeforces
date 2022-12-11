#include <cstdio>
#include <cstring>

const int MAX=100010;

char s[MAX];

int a[MAX];

int main()
{
    scanf("%s",s);
    int len=strlen(s),l=0,r=0,cnt=0;
    for (int i=0;i<len;i++)
    {
        if (s[i]=='(') l++;
        else if (s[i]==')') r++;
        else
        {
            r++;
            a[cnt++]=1;
        }
        if (r>l)
        {
            printf("-1");
            return 0;
        }
    }
    a[cnt-1]+=l-r;
    r=l;
    for (int i=len-1;i>=0;i--)
    {
        if (r>l)
        {
            printf("-1");
            return 0;
        }
        if (s[i]=='(') l--;
        else if (s[i]==')') r--;
        else break;
    }
    for (int i=0;i<cnt;i++) printf("%d\n",a[i]);
    return 0;
}