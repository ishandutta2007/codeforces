#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=n-1;i-1>=0;i-=2)
            if(a[i]<a[i-1])swap(a[i],a[i-1]);
            bool bl=true;

      for(int i=1;i<n;i++)
            if(a[i]<a[i-1])bl=false;
      if(bl)cout<<"YES"<<endl;
      else cout<<"NO"<<endl;


    }

    return 0;
}