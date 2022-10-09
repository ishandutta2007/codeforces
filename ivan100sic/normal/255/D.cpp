#include <cstdio>

long long X,Y,N,C;
long long l,r,m,o,v;

long long triang(long long x){
   if (x<=0) return 0;
   return x*(x+1)/2;
}

long long skvr(long long x){
   if (x<=0) return 0;
   return x*x;
}

long long cornerloss(long long x,long long y,long long d){
   return triang(d-x-y+1);
}

long long sideloss(long long x,long long d){
   return skvr(d-x+1);
}

long long noloss(long long d){
   return d*d+(1+d)*(1+d);
}

long long totsrcf(long long x,long long y,long long d){
   return noloss(d) - sideloss(x,d) - sideloss(y,d) - sideloss(N-x+1,d) - sideloss(N-y+1,d)
   + cornerloss(x,y,d) + cornerloss(N-x+1,y,d) + cornerloss(N-x+1,N-y+1,d) + cornerloss(x,N-y+1,d);
}

void debug(){
   scanf("%I64d",&m);
   printf("%I64d\n",totsrcf(X,Y,m));
}

int main(){
   scanf("%I64d%I64d%I64d%I64d",&N,&X,&Y,&C);
   l=0;
   r=2000000000ll;
   o=0;
   while (l<=r){
      m = (l+r)/2;
      v = totsrcf(X,Y,m);
      //printf("%I64d\n",m);
      //printf("%I64d\n",v);
      if (v>=C){
         o = m;
         r = m-1;
      } else {
         l = m+1;
      }
   }
   printf("%I64d\n",o);
   return 0;
}