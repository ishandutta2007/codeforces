#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t[1009],f[1009],s[1009];
int n,q;
int main()
{
    ios::sync_with_stdio(0);
    for(int i=1;i<=1000;i++)t[i]=-1;
    t[3]=1;
    t[5]=t[7]=0;
    f[5]=1;
    s[7]=1;
    for(int i=4;i<1001;i++)
    {
        if(i>3&&t[i-3]!=-1){t[i]=t[i-3]+1;f[i]=f[i-3];s[i]=s[i-3];continue;}
        if(i>5&&t[i-5]!=-1){f[i]=f[i-5]+1;t[i]=t[i-5];s[i]=s[i-5];continue;}
        if(i>7&&t[i-7]!=-1){t[i]=t[i-7];f[i]=f[i-7];s[i]=s[i-7]+1;continue;}
    }
        cin>>q;
        while(q--)
        {
            cin>>n;
            if(t[n]==-1)cout<<-1<<endl;
            else cout<<t[n]<<" "<<f[n]<<" "<<s[n]<<endl;
        }

    return 0;
}