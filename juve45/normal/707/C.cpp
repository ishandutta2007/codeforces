#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{

    cin>>n;

    if(n==1 || n==2)
        cout<<"-1";
    else{
long long p=1;if(n==4)
            cout<<"3 5";
            else
        if(n%2==0 && n>4)
        {
            long long p=n*n/4;
            cout<<p+1<<' '<<p-1;
        }

        else{
            cout<<p*(n*n/2)<<' '<<p*(n*n/2+1);
        }

    }

    return 0;
}