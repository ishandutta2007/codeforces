#include <iostream>

using namespace std;

int main()
{
    int n,i,j,k;
    int a[200];
    int max;
    int b[200];
    int num[100];
    int n1,n2,c1,c2;
    cin>>n;
    for(i=10;i<100;i++)
    {
        num[i]=0;
    }
    for(i=0;i<2*n;i++)
    {
        cin>>a[i];
        num[a[i]]++;
    }
    n1=0;
    n2=0;
    c1=0;
    c2=0;
    for(i=0;i<2*n;i++)
    {
        b[i]=0;
    }
    for(i=10;i<100;i++)
    {
        if(num[i]==1)
        {
            if(n1<=n2)
            {
                n1++;
                c1++;
                for(j=0;j<2*n;j++)
                {
                    if((a[j]==i)&&(b[j]==0))
                    {
                        b[j]=1;
                        break;
                    }
                }
            }else
            {
                n2++;
                c2++;
                for(j=0;j<2*n;j++)
                {
                    if((a[j]==i)&&(b[j]==0))
                    {
                        b[j]=2;
                        break;
                    }
                }
            }
        }
    }
    for(i=10;i<100;i++)
    {
        if(num[i]>1)
        {
            n1++;
            c1++;
            for(j=0;j<2*n;j++)
            {
                if((a[j]==i)&&(b[j]==0))
                {
                    b[j]=1;
                    break;
                }
            }
            n2++;
            c2++;
            for(k=j;k<2*n;k++)
            {
                if((a[k]==i)&&(b[k]==0))
                {
                    b[k]=2;
                    break;
                }
            }
            for(j=k;j<2*n;j++)
            {
                if((a[j]==i)&&(b[j]==0))
                {
                    if(c1<c2)
                    {
                        c1++;
                        b[j]=1;
                    }else
                    {
                        c2++;
                        b[j]=2;
                    }
                }
            }

        }
    }
    cout<<n1*n2<<endl;
    n1=0;
    n2=0;
    for(i=0;i<2*n;i++)
    {
        if(i>0)
        {
            cout<<" ";
        }
        if((b[i]==1)||((b[i]==0)&&(n1<n2)))
        {
            cout<<1;
            n1++;
        }else
        {
            cout<<2;
            n2++;
        }
    }
    return 0;
}