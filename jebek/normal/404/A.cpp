#include <iostream>

using namespace std;

int n;
char c[400][400];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>c[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j || i+j==n-1)
            {
                if(c[0][0]!=c[i][j])
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
            else
            {
                if(c[i][j]==c[0][0] || c[i][j]!=c[0][1])
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"YES"<<endl;
}