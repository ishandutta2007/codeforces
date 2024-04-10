#include <bits/stdc++.h>
using namespace std;

const int INF=1000000;
const int SZ=18;
int seg[1<<(SZ+1)][5][5];

void val1(int i,char c)
{
  for(int x=0;x<5;x++){
    for(int y=0;y<5;y++){
      seg[i][x][y]=INF;
    }
  }
  if(c=='2'){
    seg[i][0][0]=1;
    seg[i][0][1]=0;
    seg[i][1][1]=0;
    seg[i][2][2]=0;
    seg[i][3][3]=0;
    seg[i][4][4]=0;
  }
  else if(c=='0'){
    seg[i][0][0]=0;
    seg[i][1][1]=1;
    seg[i][1][2]=0;
    seg[i][2][2]=0;
    seg[i][3][3]=0;
    seg[i][4][4]=0;
  }
  else if(c=='1'){
    seg[i][0][0]=0;
    seg[i][1][1]=0;
    seg[i][2][2]=1;
    seg[i][2][3]=0;
    seg[i][3][3]=0;
    seg[i][4][4]=0;
  }
  else if(c=='6'){
    seg[i][0][0]=0;
    seg[i][1][1]=0;
    seg[i][2][2]=0;
    seg[i][3][3]=1;
    seg[i][4][4]=1;
  }
  else if(c=='7'){
    seg[i][0][0]=0;
    seg[i][1][1]=0;
    seg[i][2][2]=0;
    seg[i][3][3]=1;
    seg[i][3][4]=0;
    seg[i][4][4]=0;
  }
  else{
    seg[i][0][0]=0;
    seg[i][1][1]=0;
    seg[i][2][2]=0;
    seg[i][3][3]=0;
    seg[i][4][4]=0;
  }
}

void val2(int i)
{
  for(int x=0;x<5;x++){
    for(int y=0;y<5;y++){
      seg[i][x][y]=INF;
    }
  }
  for(int x=0;x<5;x++){
    for(int y=0;y<5;y++){
      for(int z=0;z<5;z++){
	seg[i][x][z]=min(seg[i][x][z],seg[2*i][x][y]+seg[2*i+1][y][z]);
      }
    }
  }
}

void cal(int i,int j,int k,int a,int b,int V[5][5])
{
  if(b<=j||k<=a){
    for(int x=0;x<5;x++){
      for(int y=0;y<5;y++){
	V[x][y]=(x==y?0:INF);
      }
    }
  }
  else if(a<=j&&k<=b){
    for(int x=0;x<5;x++){
      for(int y=0;y<5;y++){
	V[x][y]=seg[i][x][y];
      }
    }
  }
  else{
    for(int x=0;x<5;x++){
      for(int y=0;y<5;y++){
	V[x][y]=INF;
      }
    }
    int V1[5][5],V2[5][5];
    cal(2*i,j,(j+k)/2,a,b,V1);
    cal(2*i+1,(j+k)/2,k,a,b,V2);
    for(int x=0;x<5;x++){
      for(int y=0;y<5;y++){
	for(int z=0;z<5;z++){
	  V[x][z]=min(V[x][z],V1[x][y]+V2[y][z]);
	}
      }
    }
  }
}

int main()
{
  int n,q;
  scanf("%d%d",&n,&q);
  static char s[200010];
  scanf("%s",s);
  for(int i=0;i<(1<<SZ);i++){
    val1(i+(1<<SZ),i<n?s[i]:0);
  }
  for(int i=(1<<SZ)-1;i>0;i--){
    val2(i);
  }
  while(q--){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;
    int V[5][5];
    cal(1,0,1<<SZ,a,b,V);
    printf("%d\n",V[0][4]==INF?-1:V[0][4]);
  }
  return 0;
}