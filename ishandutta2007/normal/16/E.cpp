#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define INF 99999999
#define MAXN 18
using namespace std;
double win[MAXN+1][MAXN+1],live[1<<MAXN+1];
int main(){
  	int n,m=-INF;    
    scanf("%d",&n);
	  for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        scanf("%lf",&win[i][j]);

	  live[(1<<n)-1]=1.0;//initializing 2^n -1 th state(all fish still alive state)
	  for(int state=(1<<n)-1;state>0;state--)
    {
       int alivecnt=__builtin_popcountll(state);//number of fish still alive in this state will be reqd for probablity calculation	
 
       int tempi=state;
       while(tempi)
       {
          int maski=tempi&(-tempi);
          int i=__builtin_ctz(maski);//i=fish to die
          int tempj=state;
          while(tempj)
          {
                int maskj=tempj&(-tempj);
                int j=__builtin_ctz(maskj);//j=fish to eat
                
                if(maski!=maskj)
 				             live[state-(maski)]+=live[state]*win[j][i]*2/alivecnt/(alivecnt-1); //ater eating i th fish new sate=state-2^i;
                tempj=tempj-maskj;
           }
           tempi=tempi-maski;
       }
    }
	  for(int i=0;i<n;i++){
      printf("%.6lf",live[1<<i]);
      i==n-1?printf("\n"):printf(" ");
    }
//    system("PAUSE");
	return 0;
}