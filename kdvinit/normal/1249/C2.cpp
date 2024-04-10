#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        long long int n,m,cnt=0,cnt0=0,lst2=0,fst0=0,temp,ans;
        cin>>n;
        m=n;
        while(1)
        {
            if(m%3==2) lst2=1;
            if(m%3==0 && lst2==1)
            {
                lst2=0;
                fst0=cnt;
            }
            cnt++;
            m/=3;
            if(m==0) cnt0++;
            if(cnt0==2) break;
        }
        if(fst0==0) { cout<<n<<endl; continue; }
        temp=pow(3,fst0);
        ans=n+temp-(n%temp);
        cout<<ans<<endl;
    }
    return 0;
}