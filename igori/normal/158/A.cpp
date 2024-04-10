#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n; int k;
    int m[100];
    cin>>n>>k;
    int ch=0;
    for(int i=0; i<n; i++)
    {
        cin>>m[i];
    }
    for(int i=0; i<n; i++)
    {
        if(m[i]>=m[k-1])
        {
            if(m[i]>0)
                ch++;
        }
    }
    cout<<ch;

}