#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//int a[1009];
//int p[1009],s[1009];
int a[500];
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        string s;
        cin>>s;
        a['R']=a['S']=a['P']=0;
        //int r=0,p=0,s=0;
        for(int i=0;i<s.size();i++)
            a[s[i]]++;
            if(a['R']>=a['S']&&a['R']>=a['P']){for(int i=0;i<s.size();i++)cout<<"P";cout<<endl;continue;}
                if(a['S']>=a['R']&&a['S']>=a['P']){for(int i=0;i<s.size();i++)cout<<"R";cout<<endl;continue;}
                if(a['P']>=a['S']&&a['P']>=a['R']){for(int i=0;i<s.size();i++)cout<<"S";cout<<endl;continue;}
    }
    return 0;
}