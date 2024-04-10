#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int t; cin>>t;
    for(int i=0;i<t;i++)
    {
        int n; cin>>n;
        string s; cin>>s;
        
        int pos=0;
        for(int j=0;j<=4;j++)
        {
            string a="";
            for(int k=0;k<j;k++) a+=s[k];
            for(int k=n-4+j;k<n;k++) a+=s[k];
            if(a=="2020") pos=1;
        }
        
        if(pos==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    
}