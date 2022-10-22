#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int k;
    unsigned long long n,res=0;
    cin>>n>>k;
    cin>>s;
    if(n==2)
    {
        if(s[0]!=s[1])
        {
            cout<<"0"<<endl<<s;
            return 0;
        }
        if(s[0]=='A')
        {
            s[1]='B';
        }
        else
        {
            s[1]='A';
        }
        cout<<"1"<<endl<<s;
        return 0;

    }
    if(k==2)
    {unsigned long long a[2]={0,0};
        for(unsigned long long i=0; i<n; i++)
        {if(s[i]=='A'){a[i%2]++;}

        }//cout<<a[0]<<endl<<a[1]<<endl;
        if(a[0]>a[1]){res=(n+1)/2-a[0]+a[1];
        cout<<res<<endl;
        for(unsigned long long i=0;i<n;i++ ){if(i%2==0){cout<<"A";}else{cout<<"B";}}
        return 0;
        }
        if(a[0]<=a[1]){res=n/2-a[1]+a[0];cout<<res<<endl;
         for(unsigned long long i=0;i<n;i++ ){if(i%2==0){cout<<"B";}else{cout<<"A";}}
        return 0;
        }


        return 0;
    }
    for(unsigned long long i=1; i<n-1; i++)
    {
        if(s[i]==s[i-1]&&s[i]==s[i+1])
        {
            res++;
            if(s[i]=='A')
            {
                s[i]='B';
            }
            else
            {
                s[i]='A';
            }
        }
    }


    for(unsigned long long i=1; i<n-1; i++)
    {
        if(s[i]==s[i-1]||s[i]==s[i+1])
        {
            res++;
            if(s[i+1]!='A'&&s[i-1]!='A')
            {
                s[i]='A';
                continue;
            }
            if(s[i+1]!='B'&&s[i-1]!='B')
            {
                s[i]='B';
                continue;
            }
            s[i]='C';

        }
    }
    cout<<res<<endl<<s;
    return 0;
}