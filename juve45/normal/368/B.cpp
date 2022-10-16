#include <iostream>

using namespace std;

int n, m, s[100002], a[100001];
bool use[100001];

int main()
{
    int k;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];

    for(int i=n; i>0; i--)
    {
        k=a[i];
        if(use[k]==false)
        {
            s[i]=s[i+1]+1;
            use[k]=true;
        }
        else s[i]=s[i+1];
    }
    for(int i=1; i<=m; i++)
        cin>>k, cout<<s[k]<<'\n';

    return 0;

}