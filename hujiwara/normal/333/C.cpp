#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> SH(int i,int k)
{
  vector<int> v;
  v.push_back(i);
  v.push_back(-i);
  if(k>1){
    for(int l=1,a=10;l<k;l++,a*=10){
      vector<int> v1=SH(i/a,k-l),v2=SH(i%a,l);
      for(int j=0;j<v1.size();j++){
	for(int h=0;h<v2.size();h++){
	  v.push_back(v1[j]+v2[h]);
	  v.push_back(v1[j]*v2[h]);
	}
      }
    }
  }
  sort(v.begin(),v.end());
  vector<int> V;
  for(int j=0;j<v.size();j++){
    if(j==0||v[j-1]<v[j]){
      V.push_back(v[j]);
    }
  }
  return V;
}

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=0;i<10000;i++){
    vector<int> v=SH(i,4);
    for(int j=0;j<v.size();j++){
      int K=n-v[j];
      if(0<=K&&K<10000){
	printf("%04d%04d\n",K,i);
	m--;
      }
      /*else if(0<-K&&-K<10000){
	printf("%04d%04d\n",-K,i);
	m--;
	}*/
      if(m==0){
	goto END;
      }
    }
  }
 END:
  return 0;
}