// Hydro submission #6253bf9b48f78301327918e6@1649655708335
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[100],b[100];
    cin>>a>>b;
    for(int i=0;i<strlen(a);i++)
    a[i]=toupper(a[i]),
    b[i]=toupper(b[i]);
    cout<<strcmp(a,b)<<endl;
    return 0;
}