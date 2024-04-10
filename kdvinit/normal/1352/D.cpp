#include <iostream>
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
        int a[n+1];
        for(int i=1;i<n+1;i++) cin>>a[i];
        int mve,cea=0,ceb=0,tempa=0,tempb=0,cntra=0,cntrb=0,total=0;
        for(mve=1;mve<n+1;mve+=0)
        {
            if(mve%2==1)
            {

                cntra++;
                cea+=a[cntra];
                if(cntra+cntrb==n) break;
                tempa+=a[cntra];
                if(tempa>tempb)
                {
                    tempb=0;
                    mve++;
                }
            }
            else
            {
                cntrb++;
                ceb+=a[n+1-cntrb];
                if(cntra+cntrb==n) break;
                tempb+=a[n+1-cntrb];
                if(tempb>tempa)
                {
                    tempa=0;
                    mve++;
                }
            }
        }
        cout<<mve<<" "<<cea<<" "<<ceb<<endl;
    }
    return 0;
}