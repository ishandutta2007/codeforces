#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll first,a,b;
bool ball[4];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   cin>>first;
   ball[first]=1;
   for(register int i=0;i<3;i++)
   {
       cin>>a>>b;
       swap(ball[a],ball[b]);
   }
   ball[1]?cout<<1<<endl:ball[2]?cout<<2<<endl:cout<<3<<endl;
}