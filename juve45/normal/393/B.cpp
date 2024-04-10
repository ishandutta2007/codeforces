#include <iostream>
#include <cstdio>
using namespace std;

const int dmax=172;
float a[dmax][dmax], b[dmax][dmax];
int w[dmax][dmax], n;


int main()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            {
                cin>>w[i][j];

            }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            double d=1.*(w[i][j]-w[j][i])/2;
            a[i][j]=1.*w[i][j]-d;
            a[j][i]=1.*w[j][i]+d;
            b[i][j]=d;
            b[j][i]=-d;
        }
    }

    for(int i=1;i<=n;i++)
        {for(int j=1;j<=n;j++)
            {
                printf("%.6f ", a[i][j]);
            }
            cout<<'\n';
        }


    for(int i=1;i<=n;i++)
        {for(int j=1;j<=n;j++)
            {
                printf("%.6f ", b[i][j]);
            }
            cout<<'\n';
        }

        return 0;
}