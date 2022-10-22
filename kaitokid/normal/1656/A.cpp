#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100009],id[100009];
bool bl(int x,int y)
{
    return a[x]<a[y];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++){cin>>a[i];id[i]=i;}
        sort(id+1,id+n+1,bl);
        cout<<id[1]<<" "<<id[n]<<endl;
    }
    return 0;
}