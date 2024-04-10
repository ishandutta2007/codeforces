#include <iostream>

using namespace std;

int n;

int main()
{
    cin>>n;
    for(int i=1;i<n;i+=2)
        cout<<char(i%4+'a')<<char(i%4+'a');
    if(n%2==1)
        cout<<'z';
    cout<<endl;
    for(int i=1;i<n;i+=2)
        cout<<char(i%4+'a'+5)<<char(i%4+'a'+5);
    if(n%2==1)
        cout<<'z';
    cout<<endl;
    cout<<'x';
    for(int i=2;i<n;i+=2)
        cout<<char(i%4+'a'+10)<<char(i%4+'a'+10);
    if(n%2==0)
        cout<<'y';
    cout<<endl;
    cout<<'x';
    for(int i=2;i<n;i+=2)
        cout<<char(i%4+'a'+15)<<char(i%4+'a'+15);
    if(n%2==0)
        cout<<'y';
    cout<<endl;
}