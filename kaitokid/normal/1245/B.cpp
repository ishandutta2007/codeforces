#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    int q;
    cin>>q;
    while(q--)
    {
        int n,a,b,c,a1=0,b1=0,c1=0;
        string s;
        cin>>n>>a>>b>>c>>s;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='S')a1++;
            if(s[i]=='R')b1++;
            if(s[i]=='P')c1++;}
            int win=min(a,a1)+min(b,b1)+min(c,c1);
            if(win<(n+1)/2){cout<<"NO\n";continue;}
            cout<<"YES\n";
        a1=a-a1;
        b1=b-b1;
        c1=c-c1;
        for(int i=0;i<n;i++)
        {

            if(s[i]=='S'&&a>0){cout<<"R";a--;continue;}
            if(s[i]=='R'&&b>0){cout<<"P";b--;continue;}
            if(s[i]=='P'&&c>0){cout<<"S";c--;continue;}
        if(a1>0){cout<<"R";a1--;a--;continue;}
          if(b1>0){cout<<"P";b1--;b--;continue;}
   if(c1>0){cout<<"S";c1--;c--;continue;}
        }
        cout<<endl;
        }


    return 0;
}