#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
#define mo 1000000007
#include<set>
#include<vector>
#include<map>
int n;
char str[100005];
int cn[100005]={0};
int main()
{
    scanf("%d",&n);
    scanf("%s",str+1);
    for (int i=1; i<=n; i++)
        if (str[i]=='A') cn[0]++;
        else if (str[i]=='C') cn[1]++;
        else if (str[i]=='G') cn[2]++;
        else if (str[i]=='T') cn[3]++;
    sort(cn, cn+4);
    int an=0;
    for (int i=0;i<4;i++) if (cn[i]==cn[3]) an++;
    int res=1;
    for (int i=1;i<=n;++i)res=1ll*res*an%mo;
    printf("%d\n",res);
    return 0;
}