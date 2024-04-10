#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n<4) { cout<<-1<<endl; continue; }
        int y=n/2;
        if(n%2==1)
        {
            for(int i=y;i>=0;i--) cout<<2*i+1<<" ";
            cout<<4<<" "<<2<<" ";
            for(int i=3;i<=y;i++) cout<<2*i<<" ";
            cout<<endl;
            continue;
        }
        if(n%2==0)
        {
            for(int i=y;i>0;i--) cout<<(2*i)-1<<" ";
            cout<<4<<" "<<2<<" ";
            for(int i=3;i<=y;i++) cout<<2*i<<" ";
            cout<<endl;
            continue;
        }
    }
    return 0;
}