#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

char base[100005];
char app[100];
int qm;
int taken;
long long more;

int main()
{
    scanf("%s",base);
    int pl=0;
    taken=0;
    more=1;
    if ('A'<=base[0] && base[0]<='Z')
    {
        more=9;
        app[base[0]]=1;
        taken=1;
    }

    if (base[0]=='?') more=9;

    pl=1;
    while (base[pl])
    {
        if ('A'<=base[pl] && base[pl]<='Z')
        if (app[base[pl]]==0)
        {
            more=more*(10-taken);
            taken++;
            app[base[pl]]=1;
        }
        if (base[pl]=='?') qm++;
        pl++;
    }
    if (more==0)
    {
        printf("0\n");
        return 0;
    }
    cout << more;
    while (qm--) printf("0");
}