#include <bits/stdc++.h>

using namespace std;
bool bl[16];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int l,r;
  cin>>l>>r;
  for(int i=l;i<=r;i++)
    {bool s=false;
    memset(bl,false,sizeof bl);
        int q=i;
        while(q>0)
        {
            if(bl[q%10]){s=true;break;}
            bl[q%10]=true;
            q/=10;
        }
        if(s)continue;
        cout<<i;
        return 0;
    }
    cout<<-1;
    return 0;
}