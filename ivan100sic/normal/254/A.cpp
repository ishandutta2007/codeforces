#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct karta{
   int id,x;
};

karta A[600005];
int N,i,j,k,l;
bool moze;

bool cmp(karta a,karta b){
   return a.x < b.x;
}

int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   scanf("%d",&N);
   for (i=1; i<=N; i++){
      scanf("%d%d",&A[2*i-1].x,&A[2*i].x);
      A[2*i-1].id = 2*i-1;
      A[2*i].id = 2*i;
   }
   sort(A+1,A+2*N+1,cmp);
   moze=true;
   for (i=1; i<=N; i++){
      if (A[2*i-1].x != A[2*i].x) moze=false;
   }
   if (!moze){
      printf("-1\n");
      return 0;
   } else {
      for (i=1; i<=N; i++) printf("%d %d\n",A[2*i-1].id,A[2*i].id);
   }
   return 0;
}