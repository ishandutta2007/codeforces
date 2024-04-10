#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k,A=27,B=27,C=27;
        cin>>n>>k;
        char a[n];
        int freq[27]={0};
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>a[i];
            x=a[i]-96;
            freq[x]++;
        }
        sort(a,a+n);
        A=a[0]-96;
        if(freq[A]!=n)
        {
            B=a[freq[A]]-96;
            if(freq[A]+freq[B]!=n) C=1;
        }
        if(k==n) { cout<<a[k-1]<<endl ; continue; }
        if(freq[A]<k) { cout<<a[k-1]<<endl ; continue; }
        if(freq[A]>k)
        {
            if(B!=27)
            {
                for(int i=k-1;i<n;i++) { cout<<a[i]; }
                cout<<endl;
                continue;
            }
            else
            {
                int v;
                if(n%k==0) v=n/k;
                else v=(n/k)+1;
                for(int i=0;i<v;i++) { cout<<a[0]; }
                cout<<endl;
                continue;
            }
        }
        if(freq[A]==k)
        {
            if(C!=27)
            {
                for(int i=k-1;i<n;i++) { cout<<a[i]; }
                cout<<endl;
                continue;
            }
            else
            {
                int v;
                if(n%k==0) v=n/k-1;
                else v=(n/k);
                cout<<a[0];
                for(int i=0;i<v;i++) { cout<<a[k]; }
                cout<<endl;
                continue;
            }
        }
    }
    return 0;
}