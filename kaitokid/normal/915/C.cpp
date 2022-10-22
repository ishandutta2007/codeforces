#include <bits/stdc++.h> 
using namespace std;

multiset<long long>a;
stack<long long>b;
long long ans=0;
long long n,m;
int main() { 
ios::sync_with_stdio(0);
cin>>n;
while(n!=0)
{
a.insert(n%10);
n/=10;

}
cin>>m;
long long an=0;
while(m!=0)
{
b.push(m%10);
m/=10;

}
if(b.size()>a.size())
{
for(multiset<long long>::iterator it=--a.end();it!=a.begin();it--)cout<<*it;
cout<<*a.begin();
return 0;




}
while(!b.empty()&&!a.empty())
{

long long l=b.top();
b.pop();
multiset<long long>::iterator it=a.lower_bound(l);
if(it!=a.begin())
{
long long an2=an;
it--;
an2*=10;
an2+=*it;
multiset<long long>::iterator it2;
for( it2=--a.end();it2!=a.begin();it2--)
{
if(it2!=it){an2*=10;an2+=(*it2);}
//cout<<an2<<endl;


}
if(it2!=it){an2*=10;an2+=*it2;}
ans=max(ans,an2);
it++;
}

//cout<<"r"<<*it<<endl;
if(it==a.end()||*it!=l)break;
an*=10;
an+=*it;
a.erase(it);
//cout<<an<<endl;
}
ans=max(ans,an);
cout<<ans;


 return 0; }