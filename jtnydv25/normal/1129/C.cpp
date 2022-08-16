#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const int mod = 1e9 + 7;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}

const int N = 3005;
int dp[N][N];
int a[N];
// Begins Suffix Arrays implementation
// O(n log n) - Manber and Myers algorithm
 
//Usage:
// Fill str with the characters of the string.
// Call SuffixSort(n), where n is the length of the string stored in str.
 
//Output:
// pos = The suffix array. Contains the n suffixes of str sorted in lexicographical order.
//       Each suffix is represented as a single integer (the position of str where it starts).
// _rank = The inverse of the suffix array. _rank[i] = the index of the suffix str[i..n)
//        in the pos array. (In other words, pos[i] = k <==> _rank[k] = i)
//        With this array, you can compare two suffixes in O(1): Suffix str[i..n) is smaller
//        than str[j..n) if and only if _rank[i] < _rank[j]
 
int str[N]; //input
int _rank[N], pos[N]; //output
int CNT[N], _next[N]; //internal
bool bh[N], b2h[N];
 
// Compares two suffixes according to their first characters
bool smaller_first_char(int a, int b){
  return str[a] < str[b];
}
 
void suffixSort(int n){
  //sort suffixes according to their first characters
  for (int i=0; i<n; ++i){
    pos[i] = i;
  }
  sort(pos, pos + n, smaller_first_char);
  //{pos contains the list of suffixes sorted by their first character}
 
  for (int i=0; i<n; ++i){
    bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
    b2h[i] = false;
  }
 
  for (int h = 1; h < n; h <<= 1){
    //{bh[i] == false if the first h characters of pos[i-1] == the first h characters of pos[i]}
    int buckets = 0;
    for (int i=0, j; i < n; i = j){
      j = i + 1;
      while (j < n && !bh[j]) j++;
      _next[i] = j;
      buckets++;
    }
    if (buckets == n) break; // We are done! Lucky bastards!
    //{suffixes are separted in buckets containing strings starting with the same h characters}
 
    for (int i = 0; i < n; i = _next[i]){
      CNT[i] = 0;
      for (int j = i; j < _next[i]; ++j){
        _rank[pos[j]] = i;
      }
    }
 
    CNT[_rank[n - h]]++;
    b2h[_rank[n - h]] = true;
    for (int i = 0; i < n; i = _next[i]){
      for (int j = i; j < _next[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0){
          int head = _rank[s];
          _rank[s] = head + CNT[head]++;
          b2h[_rank[s]] = true;
        }
      }
      for (int j = i; j < _next[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0 && b2h[_rank[s]]){
          for (int k = _rank[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
        }
      }
    }
    for (int i=0; i<n; ++i){
      pos[_rank[i]] = i;
      bh[i] |= b2h[i];
    }
  }
  for (int i=0; i<n; ++i){
    _rank[pos[i]] = i;
  }
}
// End of suffix array algorithm
// Begin of the O(n) longest common prefix algorithm

int height[N];
// height[i] = length of the longest common prefix of suffix pos[i] and suffix pos[i+1]
void getHeight(int n){
  for (int i=0; i<n; ++i) _rank[pos[i]] = i;
  height[0] = 0;
  for (int i=0, h=0; i<n; ++i){
    if (_rank[i] > 0){
      int j = pos[_rank[i]-1];
      while (i + h < n && j + h < n && str[i+h] == str[j+h]) h++;
      height[_rank[i]] = h;
      if (h > 0) h--;
    }
  }
  for(int i = 0;i<n-1;i++)
    height[i] = height[i+1]; // LCP(i,i+1)
    height[n-1] = 0;
}
const int logN = 21;
int ceillog[5*N];
int RMQ[logN][N];

int lcp(int i,int j,int n) // lcp of suffix at indices i and j in suffix array
{
    if(i > j) swap(i, j);
    if(i==j)
        return n - pos[i];
    j--;
    int k = ceillog[j-i+2] - 1;
    assert(i+(1<<k)<=j+1);
    return min(RMQ[k][i],RMQ[k][j-(1<<k)+1]);
}
string my_str;
int main()
{
  ceillog[1]=0;
  int k;
  for(k=1;(1<<k)<5*N;k++)
    for(int i = (1<<(k-1)) + 1;i<=(1<<k);i++)
      ceillog[i] = k;
  for(int i = (1<<k);i<5*N;i++)        
    ceillog[i] = k+1;  

  int n; sd(n);

  for(int i = 0; i < n; i++){
    sd(a[i]);
    my_str += string(a[i], 1);
    bool ok = 1;
    if(i >= 3){
      if(a[i - 3] == 0 && a[i - 2] ==  0 && a[i - 1] ==  1 && a[i] == 1) ok = 0;
      if(a[i - 3] == 0 && a[i - 2] ==  1 && a[i - 1] ==  0 && a[i] == 1) ok = 0;
      if(a[i - 3] == 1 && a[i - 2] ==  1 && a[i - 1] ==  1 && a[i] == 0) ok = 0;
      if(a[i - 3] == 1 && a[i - 2] ==  1 && a[i - 1] ==  1 && a[i] == 1) ok = 0;
    }
    for(int j = 0; j <= i; j++){
      for(int z = 1; z<= 3 && z <= i - j + 1; z++) dp[j][i] = add(dp[j][i], i - j == z - 1 ? 1 : dp[j][i - z]);
      if(i - j + 1 >= 4 && ok){
        dp[j][i] = add(dp[j][i], i - j == 3 ? 1 : dp[j][i - 4]);
      }
    }
    dp[i + 1][i] = 1;
  }

  for(int i = 0;i<n;i++) str[i] = a[n - 1 - i];
  suffixSort(n);
  getHeight(n);
  int ans = 0;

  for(int i = n-1;i>=0;i--)
  {
      RMQ[0][i] = height[i];  
      for(int j = 1;i+(1<<j)<=n;j++)
          RMQ[j][i] = min(RMQ[j-1][i],RMQ[j-1][i+(1<<(j-1))]);
  }
  
  for(int i = 0; i < n; i++){
    int ind = n - 1 - i;
    int ln = 0;
    for(int j = ind + 1; j < n; j++){
      ln = max(ln, lcp(_rank[ind], _rank[j], n));
    }
    for(int j = i - ln; j >= 0; j--){
      ans = add(ans, dp[j][i]);
    }

    printf("%d\n", ans);
  }
}