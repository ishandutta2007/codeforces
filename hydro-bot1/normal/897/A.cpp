// Hydro submission #62591dfacc64917dc46651b0@1650007547135
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,l,r;
    char c1,c2;
    string s;
    cin>>n>>m>>s;
    for(i=0;i<m;i++)
    {
        cin>>l>>r>>c1>>c2;
        for(j=l-1;j<r;j++)
        if(s[j]==c1) s[j]=c2;
    }
    cout<<s<<endl;
    return 0;
}