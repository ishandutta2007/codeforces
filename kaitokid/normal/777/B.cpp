#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
multiset<int>a1,b1,a2,b2;
int ans1,ans2,n;
int main()
{
ios::sync_with_stdio(0);
cin>>n;
char x;
for(int i=0;i<n;i++)
{
cin>>x;
int y=x-'0';
a1.insert(y);
a2.insert(y);

}
for(int i=0;i<n;i++)
{
cin>>x;
int y=x-'0';
b1.insert(y);
b2.insert(y);

}

multiset<int>::iterator it=a1.begin();
multiset<int>::iterator it2;
while(it!=a1.end())
{
int d= *it;
it2=b1.lower_bound(d);
if(it2==b1.end())ans1++;
else b1.erase(it2);
it2=b2.upper_bound(d);
if(it2!=b2.end()){ans2++;b2.erase(it2);}
it++;
}

cout<<ans1<<endl<<ans2;


return 0;}