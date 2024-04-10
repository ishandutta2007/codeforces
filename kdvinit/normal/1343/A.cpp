#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        long int n;
        cin>>n;
        for(long int i=2;i<n;i++)
        {
            long int k=pow(2,i)-1;
            if(n%k==0)
            {
                n=n/k;
                break;
            }
        }
        cout<<n<<endl;
        t--;
    }
    return 0;
}