#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
multiset<int>s;
int a[100009],cn[100009];
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++){cin>>a[i];cn[a[i]]++;}
for(int i=1;i<100001;i++)if(cn[i]>0)s.insert(cn[i]);
int d=n;
while(d>0)
{
if(s.size()==1)break;
multiset<int>::iterator it=s.end();
it--;
multiset<int>::iterator  it2=it;
it2--;
//cout<<*it<<"  "<<*it2<<" "<<*s.begin()<<endl;
if((*it==(*it2)+1) && (*it2==*s.begin()))break;
multiset<int>::iterator  it3=s.begin();
it3++;
if(*it3==*it && *s.begin()==1)break;
int r=cn[a[d-1]];
cn[a[d-1]]--;
s.erase(s.lower_bound(r));
if(r>1)s.insert(r-1);
d--;
}
cout<<d;
return 0;
}