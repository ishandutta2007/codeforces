#include<cstdio>

using namespace std;

const int N=2e5+5;

int n,k;
char s[N];

int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    if(n==1)
    {
        if(k==1) printf("0\n");
        else printf("%s\n",s+1);
    }
    else
    {
        if(k)
        {
            int base=0,pos=2;
            if(s[1]!='1') s[1]='1',base++;
            while(pos<=n&&base<k)
            {
                if(s[pos]!='0')
                {
                    ++base;
                    s[pos]='0';
                }
                ++pos;
            }
        }
        printf("%s\n",s+1);
    }
    return 0;
}