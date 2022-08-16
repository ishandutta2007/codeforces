#include <bits/stdc++.h>
using namespace std;

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

const int N = 5e5+10;
 
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
const int logN = 20;
int ceillog[N];
int RMQ[logN][N];

inline int lcp(int i,int j,int n) // lcp of suffix at indices i and j in suffix array
{
    if(i==j) return n - pos[i];
    j--;
    int k = ceillog[j-i+2] - 1;
    return min(RMQ[k][i],RMQ[k][j-(1<<k)+1]);
}
char s[N];
int dp[N];


const int MEM = 1e7;
int lft[MEM],rgt[MEM],val[MEM];
int root[N], cnt = 0;

struct segtree{
    int num;
    segtree(){num = 0;}
    void push(int x, int v, int pos1, int pos2, int s = 0, int e = N - 1){
        val[pos1] = max(val[pos2], v);
        if(s==e) return;
        int mid = (s+e)/2;
        if(x<= mid){
            rgt[pos1] = rgt[pos2];
            lft[pos1] = ++cnt;
            pos2 = lft[pos2];
            pos1 = cnt;
            push(x,v, pos1,pos2, s,mid);
        }
        else{
            lft[pos1] = lft[pos2];
            rgt[pos1] = ++cnt;
            pos2 = rgt[pos2];
            pos1 = cnt;
            push(x,v, pos1,pos2, mid+1,e);
        }
    }
    void insert(int i, int position){++num;
      root[num] = ++cnt;
      push(position, i + 1, root[num], root[num - 1]);

    }
    int get(int rt, int l, int r, int s = 0, int e = N - 1){
      if(l > e || s > r) return 0;
      if(s >= l && e <= r) return val[rt];
      int mid = (s + e) >> 1;
      return max(get(lft[rt], l, r, s, mid), get(rgt[rt], l, r, mid + 1, e));
    }
} st;

int n;
bool chk(int mx, int l, int r, bool error = 0){
  int len = r - l + 1;
  if(mx < 0) return 0;
  int L, R;
  int lo = _rank[l], hi = n - 1;
  while(lo < hi){
    int mid = (lo + hi + 1) >> 1;
    if(lcp(_rank[l], mid, n) >= len){
      lo = mid;
    } else hi = mid - 1;
  }  

  R = lo;

  lo = 0, hi = _rank[l];
  while(lo < hi){
    int mid = (lo + hi) >> 1;
    if(lcp(mid, _rank[l], n) >= len){
      hi = mid;
    } else lo = mid + 1;
  }

  L = lo;

  int mxval = st.get(root[mx + 1], L, R) - 1;
  if(mxval < 0) return 0;
  return dp[mxval + len - 1] >= len;
}

int main()
{ 
  // init();
  ceillog[1]=0;
  int k;
  for(k=1;(1<<k)<N;k++)
    for(int i = (1<<(k-1)) + 1;i<=(1<<k);i++)
      ceillog[i] = k;
  for(int i = (1<<k);i<N;i++)        
    ceillog[i] = k+1;  
  
  scanf("%d", &n);
  scanf("%s", s);
  reverse(s, s + n); 
  for(int i = 0;i<n;i++)
    str[i] = s[i] - 'a';
  suffixSort(n);
  getHeight(n);

  int ans = 0;
  for(int i = n-1;i>=0;i--)
  {
      RMQ[0][i] = height[i];  
      for(int j = 1;i+(1<<j)<=n;j++)
          RMQ[j][i] = min(RMQ[j-1][i],RMQ[j-1][i+(1<<(j-1))]);
  }
  int len = 1;
  for(int i = 0; i < n; i++){
    int mx = i - 2 * len;
    while(len + 1 <= n && (chk(mx, i - len, i - 1) || chk(mx, i - len + 1, i))){
      len++;
      mx -= 2;
    }
      dp[i] = len;
      st.insert(i, _rank[i]);
      ans = max(ans, dp[i]);
      len = max(len-1, 1);
      // trace(i, dp[i]);
  }

  printf("%d\n", ans);
}