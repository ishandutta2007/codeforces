#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[300009];
bool bl[300009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++){cin>>a[i];bl[i]=0;}
        bl[0]=1;
        for(int i=1;i<=n;i++)
        {
            if((i-a[i]>0)&&(bl[i-a[i]-1]))bl[i]=true;
            if((bl[i-1])&&(i+a[i]<=n))bl[i+a[i]]=true;
        }
        if(bl[n])cout<<"YES"<<endl;
          else cout<<"NO"<<endl;

     }
    return 0;
}