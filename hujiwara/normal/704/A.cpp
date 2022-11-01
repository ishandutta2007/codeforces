#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

template<class T> class segtree
{
private:
  T *seg;
  int S;
  T ragin(int i,int j,int k,int a,int b)
  {
    return a<=j&&k<=b?seg[i]:k<=a||b<=j?0:ragin(2*i,j,(j+k)/2,a,b)+ragin(2*i+1,(j+k)/2,k,a,b);
  }
public:
  segtree(){
    S=19;
    seg=(T *)calloc(sizeof(T),1<<S+1);
  }
  void set(int i,T k){
    int p=i+(1<<S);
    seg[p]=k;
    while(p>1){
      p/=2;
      seg[p]=seg[2*p]+seg[2*p+1];
    }
  }
  T rag(int a,int b){
    return ragin(1,0,1<<S,a,b);
  }

};


int main()
{
  int n,q;
  scanf("%d%d",&n,&q);
  vector<int> s(n,0);
  vector<vector<int> > v(n);
  int t0=0,t1=0;
  segtree<int> T;
  while(q--){
    int type,x;
    scanf("%d%d",&type,&x);
    if(type==1){
      x--;
      v[x].push_back(t1);
      T.set(t1,1);
      t1++;
    }
    else if(type==2){
      x--;
      for(int i=s[x];i<v[x].size();i++){
	T.set(v[x][i],0);
      }
      s[x]=v[x].size();
    }
    else if(type==3){
      t0=max(t0,x);
    }
    printf("%d\n",T.rag(t0,t1));
  }
  return 0;
}