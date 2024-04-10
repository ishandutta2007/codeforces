#include <iostream>

using namespace std;

int l, a[100020], n;

void print()
{
    for(int i=1; i<=n; i++)
        cout<<a[i];
}

int main()
{
    int i=1;
    char c;

    while(!cin.eof())
    {
        cin>>c;
        a[i]=c-'0';
        i++;
    }

    n=i-2;

    for(i=1; i<n; i++)
    {
        if(a[i]%2==0)
        {
            if(a[i]<a[n])
            {
                int aux=a[i];
                a[i]=a[n];
                a[n]=aux;
                print();
                return 0;

            }
            else l=i;
        }

    }

    if(l!=0)
    {
        int aux=a[l];
        a[l]=a[n];
        a[n]=aux;
        print();
    }
    else
        cout<<-1;

    return 0;
}