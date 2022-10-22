#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200009],b[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int d=0;
        for(int i=0;i<n;i++){cin>>a[i];if(a[i]==0)d++;}
        for(int i=d;i<n;i++)b[i-d]=a[i];
        n-=d;
        for(int i=0;i<n;i++)a[i]=b[i];

        while(n>1)
        {
            for(int i=0;i+1<n;i++){b[i]=a[i+1]-a[i];}
            if(d>0)
            {
                d--;
                b[n-1]=a[0];
                sort(b,b+n);
                int g=0;
                for(int i=0;i<n;i++)if(b[i]==0)g++;
                d+=g;
                for(int i=g;i<n;i++)a[i-g]=b[i];
                n-=g;

                continue;
            }
            n--;
            sort(b,b+n);
            int g=0;
                for(int i=0;i<n;i++)if(b[i]==0)g++;
                d+=g;
                for(int i=g;i<n;i++)a[i-g]=b[i];
                n-=g;

    }
    if(n>0)
    cout<<a[n-1]<<endl;
    else cout<<0<<endl;
    }
    return 0;
}