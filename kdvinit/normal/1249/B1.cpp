#include <iostream>
using namespace std;

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        int a[n+1],pos[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pos[a[i]]=i;
        }
        for(int i=1;i<=n;i++)
        {
            int cnt=1,j=a[i];
            while(a[j]!=a[i])
            {
                cnt++;
                j=a[j];
            }
            cout<<cnt<<" ";
        }
        cout<<endl;
    }
    return 0;
}