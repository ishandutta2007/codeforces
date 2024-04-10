#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int Dani[13];
int N,i,j,k,l,m,d,p,t,dd;
int C[1000005];

void initdani(){
   Dani[0] = 0;
   Dani[1] = 31;
   Dani[2] = 28;
   Dani[3] = 31;
   Dani[4] = 30;
   Dani[5] = 31;
   Dani[6] = 30;
   Dani[7] = 31;
   Dani[8] = 31;
   Dani[9] = 30;
   Dani[10] = 31;
   Dani[11] = 30;
   Dani[12] = 31;
}

int mdtoday(int m,int d){
   int i;
   for (i=1; i<m; i++) d+=Dani[i];
   d+=1000;
   return d;
}

int main(){
   initdani();
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   scanf("%d",&N);
   for (j=1; j<=N; j++){
      scanf("%d%d%d%d",&m,&d,&p,&t);
      dd = mdtoday(m,d);
      //printf("%d\n",dd);
      for (i=dd-t; i<dd; i++) C[i]+=p;
   }
   k=0;
   for (i=1; i<1000005; i++) if (C[i] > k) k=C[i];
   printf("%d\n",k);
   return 0;
}