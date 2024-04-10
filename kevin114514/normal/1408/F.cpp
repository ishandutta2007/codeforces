#include<bits/stdc++.h>
using namespace std;
void dosame(int a,int b,int k)
{
    for(int i=0;i<k;i++)
        for(int j=0;j<(1<<k);j++)
            if(!(j>>i&1))
                cout<<j+a<<" "<<j+a+(1<<i)<<endl;
    return ;
}
int main()
{
    int n;
    cin>>n;
    int k=0;
    int tmp=1;
    while(tmp*2<=n)
    {
        tmp*=2;
        k++;
    }
    cout<<k*tmp<<endl;
    dosame(1,tmp,k);
    dosame(n-tmp+1,n,k);
    return 0;
}