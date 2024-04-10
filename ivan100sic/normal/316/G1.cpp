#include <cstdio>
#include <algorithm>
#include <vector>
#define prime (127)

using namespace std;

char base[2222];
long long hash[2222];
long long pw[2222];
char nw[2222];
long long nh[2222];
vector <long long> opts[10][2005];
vector <long long> solu[2005];
int low[10],up[10];

int n;

int main()
{
    scanf("%s",base+1);
    scanf("%d",&n);
    pw[0]=1;
    for (int i=1; i<=2001; i++) pw[i]=pw[i-1]*prime;

    for (int i=0; i<n; i++)
    {
        scanf("%s",nw+1);
        scanf("%d%d",&low[i],&up[i]);
        int pl=1;
        while (nw[pl])
        {
            nh[pl]=nh[pl-1]*prime+nw[pl];
            pl++;
        }

        for (int s=1; s<pl; s++)
        for (int e=s; e<pl; e++)
        opts[i][e-s].push_back(nh[e]-nh[s-1]*pw[e-s+1]);

        for (int dif=0; dif<pl-1; dif++)
        sort(opts[i][dif].begin(),opts[i][dif].end());
    }
    int len=0;
    while (base[len+1])
    {
        len++;
        hash[len]=hash[len-1]*prime+base[len];
    }

    for (int s=1; s<=len; s++)
    for (int e=s; e<=len; e++)
    {
        long long tbf=hash[e]-hash[s-1]*pw[e-s+1];
        int lu=e-s;
        char ok=1;
        for (int i=0; i<n; i++)
        {
            int gore,dole;
            int top,bot,tr;
            top=opts[i][lu].size()-1;
            bot=-1;
            while (top>bot)
            {
                tr=(top+bot+1)/2;
                if (opts[i][lu][tr]>=tbf)
                top=tr-1;
                else
                bot=tr;
            }
            dole=top;
            top=opts[i][lu].size()-1;
            bot=-1;
            while (top>bot)
            {
                tr=(top+bot+1)/2;
                if (opts[i][lu][tr]>tbf)
                top=tr-1;
                else
                bot=tr;
            }
            gore=top;

            if (gore-dole>up[i] || gore-dole<low[i])
            {
                ok=0;
                break;
            }
        }
        if (ok)
        solu[lu].push_back(tbf);
    }
    int ret=0;
    for (int i=0; i<len; i++)
    if (solu[i].size())
    {
        sort(solu[i].begin(),solu[i].end());
        ret++;
        for (int j=1; j<solu[i].size(); j++)
        if (solu[i][j]!=solu[i][j-1])
        ret++;
    }
    printf("%d\n",ret);
}