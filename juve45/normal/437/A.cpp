#include <cstdio>
#include <cstring>

using namespace std;
#define dmax 103
char a[dmax], b[dmax], c[dmax], d[dmax];
int lg[6];

bool check(int j)
{
    int nr=0;
    for(int i=1;i<=4;i++)
        if(i!=j && lg[j]>=2*lg[i])
        nr++;
    if(nr==3)
        return true;

         nr=0;
    for(int i=1;i<=4;i++)
        if(i!=j && 2*lg[j]<=lg[i])
        nr++;
    if(nr==3)
        return true;

    return false;
}

void read()
{char x, y;
        getchar();
        getchar();
        scanf("%s", a);
        lg[1]=strlen(a);
        getchar();
        getchar();
        getchar();
        scanf("%s", b);
        lg[2]=strlen(b);
        getchar();
        getchar();
        getchar();
        scanf("%s", c);
        lg[3]=strlen(c);
        getchar();
        getchar();
        getchar();
        scanf("%s", d);
        lg[4]=strlen(d);
}


int main()
{
    char val[]={"ABCD"};
int k=0, sol=0;
    read();
for(int i=1;i<=4;i++)
    if(check(i))
    k++, sol=i;
if(k==1)
    printf("%c\n", val[sol-1]);
    else printf("C\n");

    return 0;
}