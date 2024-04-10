#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct boja{
   int vr,prednja,id;
};

bool cmp(boja a,boja b){
   return a.vr < b.vr;
}

int manji(int a,int b){
   if (a<b) return a; else return b;
}

int N,i,j,k,l,BojaNadj,mm,half;
int Gore[100005],Dole[100005];
boja A[205000];
int Boje[205000],Prednje[205000],Zadnje[205000];

int main(){
   scanf("%d",&N);
   for (i=1; i<=N; i++){
      scanf("%d%d",&j,&k);
      A[2*i-1].vr = j;
      A[2*i-1].prednja = 1;
      A[2*i].vr = k;
      A[2*i].prednja = 0;
      A[2*i-1].id = i;
      A[2*i].id = i;
      Gore[i] = j;
      Dole[i] = k;
   }
   mm=N+1;
   half=(N+1)/2;
   sort(A+1,A+2*N+1,cmp);
   for (i=1; i<=2*N; i++){
      if (A[i].vr != A[i-1].vr){
         BojaNadj++;
         Boje[BojaNadj]=A[i].vr;
      }
      if (A[i].prednja==1) Prednje[BojaNadj]++; else Zadnje[BojaNadj]++;
      if (Gore[A[i].id]==Dole[A[i].id] && A[i].prednja==0) Zadnje[BojaNadj]--;
   }
   for (i=1; i<=BojaNadj; i++){
      if (Prednje[i]>=half) mm=0; else
      if (Prednje[i]+Zadnje[i]>=half){
         mm = manji(mm,half-Prednje[i]);
      }
   }
   if (mm==N+1) printf("-1\n"); else printf("%d\n",mm);
   return 0;
}