// Hydro submission #62972a4f1008115bd64b4f93@1654073935407
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,s,i,j;
    cin>>t;
    string a,b;
    for(i=0;i<t;i++)
    {
        cin>>n;s=0;
        for(j=0;j<n-2;j++)
        {
            cin>>b;
            if(!j||b[0]!=a[1])
            cout<<b,s++;
            else printf("%c",b[1]);
            a=b;
        }
        if(s==1) printf("a");
        cout<<endl;
    }
    return 0;
}