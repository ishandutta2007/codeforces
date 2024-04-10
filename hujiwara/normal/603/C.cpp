#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  /*static int g[100010];
  g[0]=0;
  for(int i=1;i<n;i++){
    bool B[3]={0};
    B[g[i-1]]=1;
    if(i%2==0){
      B[k%2==0?0:g[i/2]]=1;
    }
    int t=0;
    while(B[t]){
      t++;
    }
    g[i]=t;
    printf("%d %d\n",i,g[i]);
    }*/
  int G=0;
  for(int i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    int g;
    if(k%2==0){
      g=(a==1?1:a==2?2:a%2==0?1:0);
    }
    else{
      if(a==1){
	g=1;
      }
      else if(a==2){
	g=0;
      }
      else if(a==3){
	g=1;
      }
      else if(a%2==1){
	g=0;
      }
      else{
	int s=0;
	while(a%2==0){
	  a/=2;
	  s++;
	}
	if(a==3){
	  g=(s%2==0?1:2);
	}
	else{
	  g=(s%2==0?2:1);
	}
      }
    }
    G^=g;
  }
  puts(G==0?"Nicky":"Kevin");
  return 0;
}