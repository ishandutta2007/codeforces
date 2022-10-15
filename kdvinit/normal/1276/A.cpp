#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        cin>>a;
        int n=a.size(),ans=0,pos[n];
        for(int i=0;i<n-2;i++)
        {
            if(a[i]=='t' && a[i+1]=='w' && a[i+2]=='o')
            {
                i+=2;
                pos[ans]=i;
                ans++;
                if(i>n-3) break;
                if(a[i+1]=='n' && a[i+2]=='e')
                {
                    pos[ans-1]=i+1;
                    i+=2;
                }
            }
            if(a[i]=='o' && a[i+1]=='n' && a[i+2]=='e')
            {
                pos[ans]=i+2;
                ans++;
                i+=2;
            }
        }
        cout<<ans<<endl;
        for(int i=0;i<ans;i++) cout<<pos[i]<<" ";
        cout<<endl;
    }
    return 0;
}