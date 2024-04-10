#include <bits/stdc++.h>

using namespace std;
pair<int,int>a[300009];
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=2*(i+1);

    }
    sort(a,a+n);
    reverse(a,a+n);
    for(int i=0;i<n-1;i++)cout<<a[i].second<<" "<<a[i+1].second<<endl;
    for(int i=0;i<n;i++)
    {
        int x=a[i].first+i-1;
        cout<<a[i].second-1<<" "<<a[x].second<<endl;
        if(a[x+1].second==0)a[x+1].second=a[i].second-1;

    }
    return 0;
}