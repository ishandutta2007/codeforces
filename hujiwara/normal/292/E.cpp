#include <cstdio>

void T1(int seg[1<<18],int i,int j,int k,int a,int b,int c)
{
  if(a<=j&&k<=b){
    seg[i]=c;
  }
  else if(a<k&&j<b){
    if(seg[i]){
      seg[2*i+1]=seg[i];
      seg[2*i+2]=seg[i];
      seg[i]=0;
    }
    T1(seg,2*i+1,j,(j+k)/2,a,b,c);
    T1(seg,2*i+2,(j+k)/2,k,a,b,c);
  }
}

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static int a[100000],b[100000],seg[1<<18]={0};
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
  }
  for(int i=0;i<n;i++){
    scanf("%d",b+i);
  }
  while(m--){
    int t;
    scanf("%d",&t);
    if(t==1){
      int x,y,k;
      scanf("%d%d%d",&x,&y,&k);
      x--;
      y--;
      T1(seg,0,0,1<<17,y,y+k,x-y+n);
    }
    else if(t==2){
      int x;
      scanf("%d",&x);
      x--;
      int p=x+(1<<17)-1,c=seg[p];
      while(p){
	p=(p-1)/2;
	if(seg[p]){
	  c=seg[p];
	}
      }
      printf("%d\n",c?a[x+c-n]:b[x]);
    }
  }
  return 0;
}