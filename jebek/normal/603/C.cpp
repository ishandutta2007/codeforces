#include <iostream>
#include<algorithm>

using namespace std;

int n,k,a,ans,b[10];

int f(int a)
{
    if(a<5)
        return b[a];
    if(a%2==1)
        return 0;
    int tmp=f(a/2);
    if(tmp==1)
        return 2;
    return 1;
}

int main()
{
    b[0]=0,b[1]=1,b[2]=0,b[3]=1,b[4]=2;
    cin>>n>>k;
    k%=2;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        int tmp=0;
        if(k==0){
            if(a%2==0)
                tmp=1;
            if(a<3)
                tmp=a;
        }
        else
            tmp=f(a);
        ans^=tmp;
    }
    if(ans==0)
        cout<<"Nicky"<<endl;
    else
        cout<<"Kevin"<<endl;
}