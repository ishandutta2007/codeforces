#include <iostream>

using namespace std;
int n, k;
int main()
{
    cin>>n>>k;
    int i=0;
    while(k>0)
    {

        if(k==1)
        {
            cout<<"YES\n"<<i-1<<'\n';
            return 0;
        }
        if(k%n!=0)
        {
            cout<<"NO\n";
            return 0;
        }

    i++;
    k/=n;
}

cout<<"NO\n";
return 0;
}