#include <bits/stdc++.h>
#define pb push_back
#define vi vector <long>

using namespace std;

int main()
{
    int n,a[100],i,f=-1,b[100][2],l=0;
    cin>>n;
    for(i=0;i<n;++i)
            cin>>a[i];
    for(i=0;i<n;++i)
    {
        if(a[i]!=0)
        {
           if(f==-1) {b[l++][0]=i;b[l-1][1]=i;}
           else {b[l++][0]=f;b[l-1][1]=i;f=-1;}
        }
        else if(f==-1) f=i;
    }
    if(l==0) {cout<<"NO";exit(0);}
    cout<<"YES"<<endl;
    cout<<l<<endl;
    for(i=0;i<l;++i)
    {
        if(i==l-1 && f!=-1)
            cout<<b[i][0]+1<<" "<<n<<endl;
        else
        cout<<b[i][0]+1<<" "<<b[i][1]+1<<endl;
    }
    return 0;
}