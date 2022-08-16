#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

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

const int N = 1e3+10;
 
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
const ll INF = 1e18 + 100;
int mn_pos[N];
ll dp[N], suff_dp[N];

inline ll add(ll a, ll b){return min(a + b, INF);}

int main()
{
  ceillog[1]=0;
  ll k;
  for(k=1;(1<<k)<5*N;k++)
    for(int i = (1<<(k-1)) + 1;i<=(1<<k);i++)
      ceillog[i] = k;
  for(int i = (1<<k);i<5*N;i++)        
    ceillog[i] = k+1;  
	cin.tie(0); ios_base::sync_with_stdio(0);
  int n, m; cin >> n >> m >> k;
  string s;
  cin>>s;
  for(int i = 0;i<n;i++)
    str[i] = s[i] - 'a';
  suffixSort(n);
  getHeight(n);
  for(int i = n-1;i>=0;i--)
  {
      RMQ[0][i] = height[i];  
      for(int j = 1;i+(1<<j)<=n;j++)
          RMQ[j][i] = min(RMQ[j-1][i],RMQ[j-1][i+(1<<(j-1))]);
  }

  vector<pii> vec;
  for(int i = 0; i < n; i++) for(int j = i; j < n; j++) vec.push_back({i, j});
  sort(all(vec), [&](const pii & A, const pii & B){
	  int i1 = A.F, j1 = A.S;
	  int i2 = B.F, j2 = B.S;
	  int l1 = j1 - i1 + 1, l2 = j2 - i2 + 1;
	  int _l = min(l1, l2);
	  int l = min(_l,lcp(_rank[i1], _rank[i2], n));
	  if(l < _l){ return s[i1 + l] < s[i2 + l];}
	  if(l1 == l2) return A < B;
	  return l1 < l2;
  });

  int lo = 0, hi = sz(vec) - 1;
  while(lo < hi){
	  int mid = (lo + hi + 1) >> 1;
	  int st = vec[mid].F, en = vec[mid].S;
	  // all >= [st, en]
	  int len = en - st + 1;
	memset(dp, 0, sizeof dp);
	for(int i = n - 1; i >= 0; i--){
		int _l = min(len, n - i);
		int l = min(_l, lcp(_rank[i], _rank[st], n));
		if(l < _l){
			if(s[i + l] > s[st + l]) mn_pos[i] = i + l + 1;
			else mn_pos[i] = n + 2;
		} else{
			if(n - i >= len){
				mn_pos[i] = i + l;
			} else mn_pos[i] = n + 2;
		}
		
	}
	  for(int iter = 1; iter <= m; iter++){
		suff_dp[n] = iter == 1 ? 1 : 0;
		for(int i = n - 1; i >= 0; i--){
			suff_dp[i] = add(dp[i], suff_dp[i + 1]);
			dp[i] = suff_dp[mn_pos[i]];
		}
	  }
	//   if(now=="ab")trace(st, en, mid, now, dp[0]);
	//   if(now=="ab"){for(int i = 0; i < n; i++) trace(i, mn_pos[i]);}
	  if(dp[0] >= k){
		  lo = mid;
	  } else hi = mid - 1;
  }
  auto it = vec[lo];
  cout << s.substr(it.F, it.S - it.F + 1) << endl;
}