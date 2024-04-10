#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

#define NO "NO"
#define YES "YES"


using namespace std;

int c;
int a[10002001],p[10000000],cc[1000000];

void calc(int n)
{
    for(int i=2; i<=n; i++)
    {
           if(a[i]==0)
           {
               p[c]=i;
               c++;
               for(int j=2; j*i<=n; j++)
               {
                   a[i*j]=1;
               }
           }
    }
}

int main()
{
   
    calc(1000000);
    a[1]=1;
    int n;
    cin>>n;
    for(int j=0; j<n; j++)
    {
        long long d;
        cin>>d;
       long long fff=sqrt(d);
        if(fff*fff==d)
        {
            //cout<<d<<": ";
            int b=sqrt(d);
            if(a[b]==1)
                cout<<"NO"<<endl;
            else
                cout<<YES<<endl;

        }
        else
        {
            cout<<"NO"<<endl;
        }
    }


}