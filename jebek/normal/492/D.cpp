#include <iostream>
#include<algorithm>

using namespace std;

long long n,x,y;
int t[2000000];

int main()
{
    cin>>n>>x>>y;
    for(long long i=1;i<=y;i++)
        t[i]=i+i*x/y;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        a%=x+y;
        int k=lower_bound(t,t+y+1,a)-t;
      //  cout<<k<<" "<<t[k]<<endl;
        if(t[k]-1>=a){
            if((k*x)%y==0 && t[k]-1==a)
                cout<<"Both"<<endl;
            else
                cout<<"Vanya"<<endl;
        }
        else if((k*x)%y==0)
            cout<<"Both"<<endl;
        else
            cout<<"Vova"<<endl;
    }
}