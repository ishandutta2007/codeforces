#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <utility>
using namespace std;

char A[100005];
char S[15];
int F[15];
string St;
int N,i,j,k,l;
int d,m,y;
bool moze;
map <string, int> M;
map <string, int>::iterator it;

int Days[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
   scanf("%s",A+1);
   N = strlen(A+1);
   for (i=1; i<=N-9; i++){
      for (j=i; j<=i+9; j++) S[j-i+1] = A[j];
      for (j=1; j<=10; j++) F[j] = S[j]-48;
      d = F[1]*10 + F[2];
      m = F[4]*10 + F[5];
      y = F[7]*1000 + F[8]*100 + F[9]*10 + F[10];
      moze=true;
      for (j=1; j<=10; j++){
         if (j!=3 && j!=6){
            if (!('0' <= S[j] && S[j] <= '9')) moze=false;
         }
      }
      if (S[3]!='-') moze=false;
      if (S[6]!='-') moze=false;
      if (y>2015 || y<2013) moze=false;
      if (m<1 || m>12) moze=false;
      if (moze){
         if (d < 1 || d > Days[m]) moze=false;
      }
      if (moze){
         St = S+1;
         M[St]++;
      }
      k=0;
      for (it=M.begin(); it!=M.end(); it++){
         if (it->second > k){
            k = it->second;
            St = it->first;
         }
      }
   }
   printf("%s\n",St.c_str());
   return 0;
}