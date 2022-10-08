#include "bits/stdc++.h"

using namespace std;

vector <int> V;
vector <pair <int, vector<int> > > X;

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; i++)
    V.push_back(i+1);
  do{
    long long e = 0;
    for(int i=0; i<n; i++)
      for(int j=i; j<n; j++)
      {
         int a = V[i];
         for(int k=i+1; k<=j; k++)
            a = min(a,V[k]);
         e += a;
      }
    X.push_back(make_pair(-e,V));
  }while(next_permutation(V.begin(), V.end()));
  sort(X.begin(), X.end());
  //for(int j=0; j<X.size(); j++)
  //{
    //cerr << X[j].first << "\n";
    for(int i=0; i<n; i++)
      printf("%d ", X[m-1].second[i]);
    printf("\n");
  //}
}