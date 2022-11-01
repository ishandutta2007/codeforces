#include <cstdio>
#include <set>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  set<int> S;
  for(int i=0;i<n;i++){
    int y;
    scanf("%d",&y);
    S.insert(y);
  }
  while(1){
    int M=*S.rbegin(),m=M/2;
    while(m>0){
      if(S.find(m)==S.end()){
	S.erase(M);
	S.insert(m);
	break;
      }
      m/=2;
    }
    if(m==0){
      break;
    }
  }
  for(set<int>::iterator it=S.begin();it!=S.end();it++){
    printf("%d ",*it);
  }
  putchar('\n');
  return 0;
}