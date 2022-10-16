/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

int val(int a[],int n)
{
    int cnt=0;
    while(1)
    {
        int flag=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i+1]) { swap(a[i+1],a[i]); cnt++; flag=0; }
        }
        if(flag==1) break;
    }
    return cnt;
}

int main()
{
    int t,flag=1;
    cin>>t;
    while(t--)
    {
        flag=1;
        int n;
        cin>>n;

        int a[n+1],b[n+1],freq1[27]={0},freq2[27]={0},y;
        char x;

        for(int i=1;i<=n;i++)
        {
            cin>>x;
            y=x-96;
            a[i]=y;
            freq1[y]++;
        }

        for(int i=1;i<=n;i++)
        {
            cin>>x;
            y=x-96;
            b[i]=y;
            freq2[y]++;
        }

        for(int i=1;i<=26;i++)
        {
            if(freq1[i]!=freq2[i])
            {
                cout<<"NO"<<endl;
                flag=0;
                break;
            }
        }

        if(flag==0) continue;

        for(int i=1;i<=26;i++)
        {
            if(freq1[i]>1)
            {
                cout<<"YES"<<endl;
                flag=0;
                break;
            }
        }

        if(flag==0) continue;

        int cnt1=val(a,n);
        int cnt2=val(b,n);
        cnt1%=2;
        cnt2%=2;

        if(cnt1==cnt2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}