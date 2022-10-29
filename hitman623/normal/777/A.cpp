#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int main()
{
    long long n,x;
    cin>>n>>x;
    n%=6;
    while(n%6!=0)
    {
        n++;
        switch(n)
        {
            case 1:if(x==0) x=1;else if(x==1) x=0;break;
            case 2:if(x==1) x=2;else if(x==2) x=1;break;
            case 3:if(x==0) x=1;else if(x==1) x=0;break;
            case 4:if(x==1) x=2;else if(x==2) x=1;break;
            case 5:if(x==0) x=1;else if(x==1) x=0;break;
            case 6:if(x==1) x=2;else if(x==2) x=1;break;
        }
    }
    cout<<x;
    return 0;
}