// Hydro submission #625cec3b81ef68d42bcbae3d@1650256956415
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int h1,m1,h2,m2,s;
    scanf("%d:%d\n%d:%d\n",&h1,&m1,&h2,&m2);
    s=(h1*60+m1+h2*60+m2)/2;
    printf(s/60<10?"0%d:":"%d:",s/60);
    printf(s%60<10?"0%d\n":"%d\n",s%60);
    return 0;
}