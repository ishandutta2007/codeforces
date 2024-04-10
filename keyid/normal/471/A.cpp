#include <cstdio>
#include <cstring>

int main()
{
    int a[6],t[2],m=0;
    for (int i=0;i<6;i++) scanf("%d",&a[i]);
    for (int i=0;i<6;i++)
    {
        int cnt=1;
        bool v[6];
        memset(v,0,sizeof(v));
        v[i]=true;
        for (int j=0;j<6;j++) if (i!=j&&a[i]==a[j]) 
        {
            v[j]=true;
            if (++cnt==4)
            {
                for (int k=0;k<6;k++) if (!v[k]) t[m++]=a[k];
                break;
            }
        }
        if (m) break;
    }
    if (!m) printf("Alien");
    else if (t[0]==t[1]) printf("Elephant");
    else printf("Bear");
    return 0;
}