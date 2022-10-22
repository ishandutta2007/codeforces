#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;

#define pb push_back

queue < pair < int, int > > sweep;
vector<int> v, dog;
int n,x;
int a[1000100],b[1000100];

int main() {
  memset(a,0,1000100);
  memset(b,0,1000100);
  cin >> n;
  for(int i=0;i<n;i++) {
    cin >> x;

    if(b[x]!=1)
      v.pb(x);

    b[x]=1;

  }
  sort(v.begin(),v.end());
  int maxx=v.back();
  for(int i=0;i<v.size();i++) {
    for(int j=v[i];j<=maxx;j+=v[i]) {
      a[j]=v[i];
    }
  }
  for(int i=0;i<10;i++) {
   // cout << a[i];
  }
  int tmp=0;
  sweep.push(make_pair(0,0));
  int maksimalna=-1;
  for(int curr=1;curr<=maxx;curr++) {

    while(sweep.front().first+sweep.front().second < curr && !sweep.empty()) {
      sweep.pop();
    }
    sweep.push(make_pair(curr,a[curr]-1));
    tmp=curr-sweep.front().first;
    if(tmp>maksimalna && b[curr]==1) maksimalna=tmp;
    //cout << tmp;
  }
  cout << maksimalna;
  return 0;
}