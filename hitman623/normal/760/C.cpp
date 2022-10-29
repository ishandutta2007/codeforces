#include <bits/stdc++.h>

using namespace std;
long long n,a[200005][3]={0},f=0,i,s=0,t,p,tt,q=0,b[200005],ff=0;
int main()
{
    cin>>n;
    for(i=0;i<n;++i)
        {cin>>a[i][0];a[i][1]=0;a[i][2]=0;}
        for(i=0;i<n;++i)
            {cin>>b[i];
            if(b[i]) {f++;}}
            if(f%2==0) ff++;
      s=0;
    for(i=0;i<n;++i)
    {
        f=0;t=0;
        if(a[i][1]==0)
        {
            p=i;
           while(1)
           {
             if(a[p][2]==-1) {s++;break;}
             if(a[p][2]==-2) {q++;break;}
             a[p][1]=++t;
             a[p][2]=-1;
             p=(a[p][0]-1+n)%n;
           }
            p=i;
           while(1)
           {
             if(a[p][2]==-1) a[p][2]--;
             else break;
             p=(a[p][0]-1+n)%n;
           }
        }
    }
   //cout<<s<<q;
    cout<<s+q+ff-(s==1);
    return 0;
}