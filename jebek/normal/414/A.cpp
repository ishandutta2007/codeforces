#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

using namespace std;

typedef pair<int,int> pii;

long long n,k,m,x;

int main()
{
    cin>>n>>k;
    m=n%2;
    n=n/2;
    if(k<n)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(k==0)
    {
        cout<<1<<endl;
        return 0;
    }
    if(n==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    x=1;
    for(int i=k%n;i<n;i++)
    {
        cout<<(k/n)*(x)<<" "<<(k/n)*(x+1)<<" ";
        x+=2;
    }
    for(int i=0;i<k%n;i++)
    {
        cout<<(k/n+1)*(x)<<" "<<(k/n+1)*(x+1)<<" ";
        x+=2;
    }
    if(m==1)
        cout<<1000000000<<endl;
    else
        cout<<endl;
}