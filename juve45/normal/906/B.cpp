#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 1001000
#define NMAX 
#define MMAX 

using namespace std;

int n, k, x, m, mat[DMAX], N;
string s;
bool sw = false;


template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
  out << v.size() << '\n';
  for(auto e : v) out << e << ' ';
  return out;
}

inline int get(int i, int j) {
  return mat[(i - 1) * N + j];
}

void setV(int i, int j, int val) {
  mat[(i - 1) * N + j] = val;
}



int main()
{
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  N = m;
  if(n == 1 && m == 1) {
    cout << "YES\n1\n";
    return 0;
  }

  if(n > m) swap(n, m), sw = true, N = n;
  
  if(m <= 2 || m == 3 && n <= 2) {
    cout << "NO\n";
    return 0;
  }

  if(n == 1 && m == 4) {
    if(sw) cout << "YES\n2\n4\n1\n3\n"; 
    else cout << "YES\n2 4 1 3\n";
    return 0;
  }

  if(n == 1) {
    cout << "YES\n";
    if(sw) {
      for(int i = 1; i <= m; i+=2) cout << i << '\n';
      for(int i = 2; i <= m; i+=2) cout << i << '\n';   
    }
    else {
      for(int i = 1; i <= m; i+=2) cout << i << ' ';
      for(int i = 2; i <= m; i+=2) cout << i << ' ';   
    }    
    return 0;
  }

  if(n == 3 && m == 3) {
    cout << "YES\n";
    cout << "6 1 8\n7 5 3\n2 9 4\n";
    return 0;
  }
  cout << "YES\n";
  int val = 0;
  if(sw)  {

    swap(n, m);
    for(int i = 0; i < n; i++)
      for(int j = 1; j <= m; j++)
        setV((i + (j - 1) * 2) % n + 1, j, ++val);

    // for(int i = 1; i <= n; i++) 
    //   for(int j = 1; j <= m; j++) 
    //     cout << get(i, j) << " \n"[j == m];

    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++)
        if(i % 2 == 1) cout << get(i, j % m + 1) << " \n"[j == m];
        else cout << get(i, j) << " \n"[j == m];

  }
  else {
    
    for(int i = 1; i <= n; i++)
      for(int j = 0; j < m; j++) 
        setV(i, (j + (i - 1) * 2) % m + 1, ++val);
    
    // for(int i = 1; i <= n; i++) 
    //   for(int j = 1; j <= m; j++) 
    //     cout << get(i, j) << " \n"[j == m];

    for(int i = 1; i <= n; i++) 
      for(int j = 1; j <= m; j++) 
        if(j % 2 == 1) cout << get(i % n + 1, j) << " \n"[j == m];
        else cout << get(i, j) << " \n"[j == m];

  }


    
      // if(sw) cout << get(j, i) << " \n"[j == n];




}