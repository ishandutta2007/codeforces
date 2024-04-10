#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll s,v1,v2,t1,t2,tt1,tt2;
int main()
{
   cin>>s>>v1>>v2>>t1>>t2;
   tt1=s*v1+2*t1;
   tt2=s*v2+2*t2;
   tt1<tt2?cout<<"First"<<endl:tt1==tt2?cout<<"Friendship"<<endl:cout<<"Second"<<endl;
}