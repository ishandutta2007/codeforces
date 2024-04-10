// Hydro submission #6253d29eca53060146717154@1649660575432
#include<bits/stdc++.h>
using namespace std;
string s,c;
int main()
{   int n,i,t=0;
    cin>>n>>c;
    for(i=1;i<n;i++)
    {
        cin>>s;
        if(s!=c) t++;
        c=s;
    }
    printf("%d\n",t+1);
    return 0;
}