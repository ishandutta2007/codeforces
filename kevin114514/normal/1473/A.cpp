#include<bits/stdc++.h>
using namespace std;
int x[110];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        sort(x+1,x+n+1);
        if(x[n]<=d||x[1]+x[2]<=d)
            puts("YES");
        else    puts("NO");
    }
    return 0;
    
}