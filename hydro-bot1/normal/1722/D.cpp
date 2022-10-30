// Hydro submission #631f2ffc32ae6c3198c90f12@1662988285766
#include<bits/stdc++.h>
using namespace std;
int c[200001];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int t,n,i,j;
    long long a;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;a=0;
        s=' '+s;
        for(i=1;i<=n;i++)
        switch(s[i])
        {
            case 'L':a+=i-1;c[i]=max(n-i-i+1,0);break;
            case 'R':a+=n-i;c[i]=max(i-n+i-1,0);break;
        }
        sort(c+1,c+n+1,cmp);
        for(i=1;i<=n;i++)
        {
            a+=c[i];
            printf("%lld ",a);
        }
        cout<<endl;
    }
    return 0;
}