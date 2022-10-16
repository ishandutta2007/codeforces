#include <bits/stdc++.h>

using namespace std;

int n, a, b, f[444], m[444], ans;
char c;
int main()
{
    //freopen("in.txt", "r", stdin);
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>c>>a>>b;
    
    if(c=='F')
    {
        f[a]++;
        f[b+1]--;
    }
    else{
        m[a]++;
        m[b+1]--;
    }
}
    int M=0, F=0;
    for(int i=1;i<=366;i++)
    {
        M+=m[i];
        F+=f[i];
        if(min(M, F)>ans)
            ans=min(M, F);
    }
    
    cout<<2*ans<<'\n';



    return 0;
}