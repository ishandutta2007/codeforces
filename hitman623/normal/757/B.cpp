#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,an=0,a[100003]={0},c[100004]={0},i,cnt,x,j;
    cin>>n;
    for(i=0;i<n;++i)
        {cin>>x;
        a[x]++;}
        for(i=2;i<100001;++i)
        {
            if(c[i]==0)
            {
                for(j=2*i;j<100001;j+=i)
                {
                    c[j]=1;
                }
                //cout<<i<<"  ";
            }
        }
    for(i=2;i<100001;++i)
    {
        cnt=0;
        if(c[i]==0)
        {
            for(j=i;j<100001;j+=i)
            {
                if(a[j]>0)
                {cnt+=a[j];}
            }
        }
        an=max(cnt,an);
    }
    if(an==0) an=1;
    cout<<an;
    return 0;
}