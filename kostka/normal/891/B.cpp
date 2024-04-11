//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 22;
int n, a[MAXN], b[MAXN];

bool check() {
  for(int mas=1; mas<(1<<n)-1; mas++) {
    long long suma = 0, sumb = 0;
    for(int i=0; i<n; i++) {
      if((1<<i) & mas) {
        suma += a[i];
        sumb += b[i];
      }
    }
    if(suma == sumb) return false;
  }
  return true;
}

int main()
{
  srand(15061994);
  ios_base::sync_with_stdio(0);
  cin >> n;
  vector <int> ID;
  for(int i=0; i<n; i++) {
    cin >> a[i];
    ID.push_back(i);
  }
  sort(ID.begin(), ID.end(), [&](int p, int q){
    return a[p] < a[q];
  });
  for(int i=0; i<n; i++) b[ID[i]] = a[ID[(i-1+n)%n]];
  //assert(check());
  for(int i=0; i<n; i++) cout << b[i] << " ";
  cout << "\n";
  return 0;
}