// Hydro submission #62591b5ccc64917dc4664fad@1650006877159
#include<bits/stdc++.h>
using namespace std;
int b,c,s,t;
int main()
{
    int n,a,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        if(!b) b=a,s++;
        else if(b-a&&!c) c=a,t++;
        else if(a==b) s++;
        else if(a==c) t++;
    }
    if(s==t&&s==n/2)
    printf("YES\n%d %d\n",b,c);
    else printf("NO\n");
    return 0;
}