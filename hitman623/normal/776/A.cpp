#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair

using namespace std;

int main()
{
    long n,i;
    char a[20],b[20],aa[20],bb[20];
    cin>>aa>>bb;
    cin>>n;
    cout<<aa<<" "<<bb<<endl;
    for(i=0;i<n;++i)
    {
        cin>>a>>b;
        if(strcmp(aa,a)==0) strcpy(aa,b);
        else strcpy(bb,b);
        cout<<aa<<" "<<bb<<endl;
    }
    return 0;
}