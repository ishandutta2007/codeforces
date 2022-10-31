// Hydro submission #6290849237e0de7afd399e93@1653638290413
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int h,m,d;
    scanf("%d%d:%d",&d,&h,&m);
    if(d-24&&(!h||h>12)||d-12&&h>23)
    printf(d-12?"0%d:":h%10?"0%d:":"10:",h%10);
    else printf(h>9?"%d:":"0%d:",h);
    if(m>59) printf("0%d\n",m%10);
    else printf(m>9?"%d\n":"0%d\n",m);
    return 0;
}