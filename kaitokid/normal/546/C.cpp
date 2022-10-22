#include <bits/stdc++.h>

using namespace std;
deque<int>a,b;
vector <deque <int> > f;
int main()
{int n,k1,k2,x,l=0,g,h;
cin>>n>>k1;
for(int i=0;i<k1;i++)
{
    cin>>x;
    a.push_back(x);
}
cin>>k2;
for(int i=0;i<k2;i++)
{
    cin>>x;
    b.push_back(x);
}


while(a.size()<n&&b.size()<n)
{
    if(a[0]>b[0]){a.push_back(b[0]);a.push_back(a[0]);a.pop_front();b.pop_front();}
else{if(b[0]>a[0]){b.push_back(a[0]);b.push_back(b[0]);a.pop_front();b.pop_front();}}
f.push_back(a);
f.push_back(b);
l++;

if(count(f.begin(),f.end(),a)!=1&&count(f.begin(),f.end(),b)!=1){cout<<"-1";return 0;}

}
cout<<l<<" ";
if(a.size()==n){cout<<"1";}
if(b.size()==n){cout<<"2";}


    return 0;
}