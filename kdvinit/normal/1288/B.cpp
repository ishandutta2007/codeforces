#include <iostream>
using namespace std;

long long int conc(long long int a, long long int b)
{
    int cntr=0;
    while(1)
    {
        if(b%10!=b)
        {
            b/=10;
            cntr++;
        }
        else return a*cntr;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        long long int a,b;
        cin>>a>>b;
        cout<<conc(a,b+1)<<endl;
        t--;
    }
    return 0;
}