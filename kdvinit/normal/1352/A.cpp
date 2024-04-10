#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int temp=n;
        int cnt=0;
        while(n>0)
        {
            if(n%10!=0) cnt++;
            n/=10;
        }
        cout<<cnt<<endl;
        cnt=0;
        int cntr=0;
        n=temp;
        while(n>0)
        {
            if(n%10!=0)
            {
                cout<<(n%10)*pow(10,cntr)<<" ";
                cnt++;
            }
            cntr++;
            n/=10;
        }
        cout<<endl;
    }
    return 0;
}