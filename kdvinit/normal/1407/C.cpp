#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin>>n;

    if(n==1) { cout<<"! 1"<<endl; return 0; }

    int i=1,j=2,a[n+1]={0},x,y,freq[n+2]={0};
    freq[1]=1;freq[2]=1;

    for(int k=1;k<n;k++)
    {
        cout<<"? "<<i<<" "<<j<<endl; cin>>x;
        cout<<"? "<<j<<" "<<i<<endl; cin>>y;

        if(x>y)
        {
            a[i]=x;
            while(freq[i]!=0) i++;
            freq[i]=1;
        }
        else
        {
            a[j]=y;
            while(freq[j]!=0) j++;
            freq[j]=1;
        }
    }

    for(int k=1;k<=n;k++) { if(a[k]==0) a[k]=n; }
    cout<<"! ";
    for(int k=1;k<=n;k++) cout<<a[k]<<" ";
    cout<<endl;

    return 0;
}