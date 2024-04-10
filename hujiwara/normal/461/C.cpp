#include <cstdio>

void segp(int *seg,int i,int k)
{
  int p=i+(1<<17);
  seg[p]+=k;
  while(p>1){
    p=p/2;
    seg[p]+=k;
  }
}

int segs(int *seg,int i,int j,int k,int a,int b)
{
  return a<=j&&k<=b?seg[i]:b<=j||k<=a?0:segs(seg,2*i,j,(j+k)/2,a,b)+segs(seg,2*i+1,(j+k)/2,k,a,b);
}

int main()
{
  int n,q;
  scanf("%d%d",&n,&q);
  static int seg[1<<18]={0};
  for(int i=0;i<n;i++){
    seg[i+(1<<17)]=1;
  }
  for(int i=(1<<17)-1;i>0;i--){
    seg[i]=seg[2*i]+seg[2*i+1];
  }
  bool b=0;
  int A=0,B=n;
  while(q--){
    int Q;
    scanf("%d",&Q);
    if(Q==1){
      int L,l;
      scanf("%d",&L);
      if(b){
	l=B-L;
      }
      else{
	l=A+L;
      }
      //printf("%d %d %d\n",A,B,l);
      if(l-A>=B-l){
	for(int i=l;i<B;i++){
	  int k=seg[i+(1<<17)];
	  //printf("%d\n",k);
	  segp(seg,i,-k);
	  segp(seg,l-(i-l)-1,k);
	}
	B=l;
	if(!b){
	  b=1;
	}
      }
      else{
	for(int i=A;i<l;i++){
	  int k=seg[i+(1<<17)];
	  //printf("%d\n",k);
	  segp(seg,i,-k);
	  segp(seg,l+(l-i)-1,k);
	}
	A=l;
	if(b){
	  b=0;
	}
      }
    }
    else if(Q==2){
      int p1,p2;
      scanf("%d%d",&p1,&p2);
      int r1,r2;
      if(b){
	r2=B-p1;
	r1=B-p2;
      }
      else{
	r1=A+p1;
	r2=A+p2;
      }
      printf("%d\n",segs(seg,1,0,1<<17,r1,r2));
    }
    /*for(int i=0;i<n;i++){
      printf("%d ",seg[i+(1<<17)]);
    }
    printf("\n%d %d %d\n",A,B,b);*/
  }
  return 0;
}