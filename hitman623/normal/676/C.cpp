#include <iostream>

using namespace std;

int main()
{
	long n,k,c=0,ans=0,i,j=0,ck=0,f=0;
	char a[200005];
	cin>>n>>k>>a;
    for(i=0;i<n;++i)
    {
        if(a[i]=='b') ck++;
        c++;
        if(ck>k) {ans=max(ans,c-1);ck--;while(a[j++]=='a')c--;c--;}
    }
    ans=max(ans,c);
    ck=0;j=0;c=0;
    for(i=0;i<n;++i)
    {
        if(a[i]=='a') ck++;
        c++;
        if(ck>k) {ans=max(ans,c-1);ck--;while(a[j++]=='b')c--;c--;}
    }
    ans=max(ans,c);
    cout<<ans;
    return 0;
}