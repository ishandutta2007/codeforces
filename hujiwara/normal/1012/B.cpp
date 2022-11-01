#include <bits/stdc++.h>
using namespace std;


class union_find{
public:
  int c;
  int uf[300000];
  union_find(int n){
    c=0;
    for(int i=0;i<n;i++){
      uf[i]=-1;
    }
  }
  int root(int i)
  {
    return uf[i]<0?i:uf[i]=root(uf[i]);
  }
  void unite(int i,int j)
  {
    i=root(i),j=root(j);
    if(i!=j){
      c++;
      if(-uf[i]<-uf[j]){
	uf[i]=j;
      }
      else if(-uf[i]>-uf[j]){
	uf[j]=i;
      }
      else{
	uf[i]=j;
	uf[j]--;
      }
    }
  }
};


int main()
{
  int n,m,q;
  scanf("%d%d%d",&n,&m,&q);
  vector<pair<int,int> > e(q);
  for(int i=0;i<q;i++){
    scanf("%d%d",&(e[i].first),&(e[i].second));
    e[i].first--,e[i].second--;
  }
  sort(e.begin(),e.end());
  union_find uf(m);
  int ans=-1;
  for(int i=0;i<q-1;i++){
    if(e[i].first==e[i+1].first){
      uf.unite(e[i].second,e[i+1].second);
    }
  }
  for(int y=0;y<m;y++){
    if(uf.uf[y]<0){
      ans++;
    }
  }
  vector<int> ct(n,0);
  for(int i=0;i<q;i++)ct[e[i].first]++;
  for(int x=0;x<n;x++){
    if(ct[x]==0)
      ans++;
  }
  printf("%d\n",ans);
  return 0;
}