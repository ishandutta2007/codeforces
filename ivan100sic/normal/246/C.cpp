#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;

map <int, bool> Used;
int N,K,A[100],Os,i,j;
vector < vector<int> > S;
vector < vector<int> >::iterator it;
vector <int> tmp;

int suma(vector <int> X){
   int i,j=0;
   for (i=0; i<X.size(); i++) j+=X[i];
   return j;
}

void stampaj(vector <int> X){
   int i,j=0;
   printf("%d",X.size()-1);
   for (i=1; i<X.size(); i++) printf(" %d",X[i]);
   puts("");
}

int main(){
   scanf("%d%d",&N,&K);
   for (i=1; i<=N; i++) scanf("%d",A+i);
   sort(A+1,A+N+1);
   tmp.clear();
   tmp.push_back(0);
   S.push_back(tmp);
   for (i=1; i<=N; i++){
      Os = S.size();
      for (j=0; j<Os; j++){
         if (S.size()>K+10) goto dosta;
         if (!Used[suma(S[j]) + A[i]]){
            tmp = S[j];
            tmp.push_back(A[i]);
            S.push_back(tmp);
            Used[suma(S[j]) + A[i]]=true;
         }
      }
   }
   dosta:
   for (j=1; j<=K; j++) stampaj(S[j]);
   return 0;
}