#include <cstdio>
#include <map>
using namespace std;

struct Key
{
  int k;
  long long M;
  Key(int k1,long long M1){
    k=k1;
    M=M1;
  }
};

bool operator<(Key K1,Key K2)
{
  return K1.k!=K2.k?K1.k<K2.k:K1.M<K2.M;
}

map<Key,int> Map;

int grandy(int k,long long M)
{
  Key K(k,M);
  if(Map.find(K)!=Map.end()){
    return Map[K];
  }
  bool b[1000]={0};
  for(int i=0;i<k;i++){
    if(!((M>>i)&1)){
      long long N=M;
      for(int j=i;j<k;j+=i+1){
	N|=1<<j;
      }
      int p=grandy(k,N);
      b[p]=1;
    }
  }
  int l=0;
  while(b[l]){
    l++;
  }
  return Map[K]=l;
}

int main()
{
  //printf("0\n");
  int G[30]={0,
1,
2,
1,
4,
3,
2,
1,
5,
6,
2,
1,
8,
7,
5,
9,
8,
7,
3,
4,
7,
4,
2,
1,
10,
9,
3,
6,
11,
12,
};
  /*for(int i=1;i<30;i++){
    G[i]=grandy(i,0);
    printf("%d,\n",G[i]);
  }
  return 0;*/
  int n;
  scanf("%d",&n);
  long long m=n;
  bool b[100000]={0};
  int F=0;
  for(long long a=2;a*a<=n;a++){
    if(!b[a]){
      long long c=a;
      int L=0;
      while(c<=n){
	if(c*c<=n){
	  b[c]=1;
	}
	m--;
	c*=a;
	L++;
      }
      /*if(L>29){
	printf("%d %d",L,G[L]);
	}*/
      F^=G[L];
    }
  }
  if(m%2){
    F^=1;
  }
  if(!F){
    puts("Petya");
  }
  else{
    puts("Vasya");
  }
  return 0;
}