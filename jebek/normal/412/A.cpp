#include <iostream>

using namespace std;

int n,k;
char c[200];

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    if(k>n/2)
    {
        while(k<n)
        {
            cout<<"RIGHT"<<endl;
            k++;
        }
        while(k>1)
        {
            cout<<"PRINT "<<c[k]<<endl<<"LEFT"<<endl;
            k--;
        }
        cout<<"PRINT "<<c[k]<<endl;
    }
    else
    {
        while(k>1)
        {
            cout<<"LEFT"<<endl;
            k--;
        }
        while(k<n)
        {
            cout<<"PRINT "<<c[k]<<endl<<"RIGHT"<<endl;
            k++;
        }
        cout<<"PRINT "<<c[k];
    }
}