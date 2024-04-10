#include <bits/stdc++.h>

using namespace std;

int main()
{
  unsigned long long n,l=0;
  vector < pair <unsigned long long,unsigned long long> >p;
  pair <unsigned long long ,unsigned long long> pr;
  cin>>n;
  for (unsigned long long i=0;i<n;i++)
  {cin>>pr.first;
  pr.second =i;
   p.push_back(pr);
  }
  sort(p.begin(),p.end());
  for(unsigned long long i=0;i<n;i++)
  {l=max(l,p[i].second);
  p[i].first=p[i].second;
  p[i].second=l-p[i].second;
  }
  sort(p.begin() ,p.end());
  for(unsigned long long i=0;i<n;i++)
  {long long j=p[i].second-1;
      cout<<j<<" ";
  }
    return 0;
}