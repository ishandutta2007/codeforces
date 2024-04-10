// Hydro submission #62972892b0c5e75beb158065@1654073508859
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i,j;
    string s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>s;
        for(j=0;j<n;j++)
        switch(s[j])
        {
            case 68:printf("U");break;
            case 76:printf("L");break;
            case 82:printf("R");break;
            case 85:printf("D");break;
        }
        cout<<endl;
    }
    return 0;
}