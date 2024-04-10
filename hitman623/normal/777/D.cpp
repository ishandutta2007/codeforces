#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,i,m,j,f=0;
    string s[500005],t;
    cin>>n;
    for(i=0;i<n;++i)
        cin>>s[i];
    for(i=n-2;i>=0;i--)
    {
        if(s[i]<=s[i+1]) continue;
        else
        {
            f=0;
            m=min(s[i+1].length(),s[i].length());
            for(j=0;j<m;++j)
                {
                    if(s[i][j]<=s[i+1][j])
                    t.push_back(s[i][j]);
                    else {s[i]=t;t.clear();f=1;break;}
                }
            if(f==0) s[i]=t;
            t.clear();
        }
    }
    for(i=0;i<n;++i)
    cout<<s[i]<<endl;
    return 0;
}