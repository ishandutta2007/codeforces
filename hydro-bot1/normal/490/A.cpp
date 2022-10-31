// Hydro submission #6255053417cd4d0a41764638@1649739061339
#include<bits/stdc++.h>
using namespace std;
int m[30000],p1[10000],p2[10000],p3[10000],s1,s2,s3,s;
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m[i];
        switch(m[i])
        {
            case 1:p1[s1]=i+1;s1++;break;
            case 2:p2[s2]=i+1;s2++;break;
            case 3:p3[s3]=i+1;s3++;break;
        }
    }
    s=min(s1,min(s2,s3));
    printf("%d\n",s);
    for(i=0;i<s;i++)
    printf("%d %d %d\n",p1[i],p2[i],p3[i]);
    return 0;
}