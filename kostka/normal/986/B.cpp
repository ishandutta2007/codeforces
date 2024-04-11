//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

const int MAXN = 1000007;
static int tab[MAXN], tmp[MAXN];
ll inversions;

void merge(int a, int b) {
  if (a==b or a+1==b) return;
  int m = (a+b)/2;
  merge(a,m);
  merge(m,b);
  int i=a, j=m, k=a;
  while(i<m && j<b) {
    if(tab[i]<tab[j]) tmp[k++] = tab[i++];
    else {
      tmp[k++] = tab[j++];
      inversions += m-i;
    }
  }
  while(i<m) tmp[k++] = tab[i++];
  while(j<b) tmp[k++] = tab[j++];
  for(k=a; k<b; k++) tab[k] = tmp[k];
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i=0; i<n; i++) cin >> tab[i];
  merge(0, n);
  cerr << inversions << "\n";
  puts(((inversions % 2) == ((3LL*n) % 2)) ? "Petr" : "Um_nik");
  return 0;
}