// Hydro submission #6253c378ca53060146715ad2@1649656697552
#include<bits/stdc++.h>
using namespace std;
int m[1000],s;
int main()
{
    int n,i,a;
    cin>>n>>m[0];
    for(i=1;i<n;i++)
    {
        cin>>a;
        sort(m,m+i);
        if(a>m[i-1]||a<m[0])
        s++;
        m[i]=a;
    }
    printf("%d\n",s);
    return 0;
}