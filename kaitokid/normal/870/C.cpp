#include <iostream>

using namespace std;

int main()
{
    int q,n;
    cin>>q;
    while(q--)
    {
        cin>>n;
        if(n==2){cout<<-1<<endl;continue;}
        if(n%2==0){cout<<n/4<<endl;continue;}
        if(n<9){cout<<-1<<endl;continue;}
        n-=9;
        if(n==2){cout<<-1<<endl;continue;}
        cout<<1+(n/4)<<endl;

    }
    return 0;
}