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

template<class T,class U>
ostream& operator<<(ostream& os,const map<T, U> & mp){
	os << "{";
	int i = 0;
	for(auto it : mp){
		if(i) os<<", ";
		os << it;
		i++;
	}
	os << "}";	
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

const int N = 5e5+10;
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
    if(i>j||j>=n)
        return -1;
    if(i==j)
        return n - pos[i];
    j--;
    int k = ceillog[j-i+2] - 1;
    assert(i+(1<<k)<=j+1);
    return min(RMQ[k][i],RMQ[k][j-(1<<k)+1]);
}
char s[N];
int main()
{
	
  scanf("%s", s);
  int n = strlen(s);
  for(int i = 0;i<n;i++)
    str[i] = s[i] - 'a';
  suffixSort(n);
  getHeight(n);
  int ind = -1, rnk = n + 1;

for(int i = 0; i < n; i++){
	if(_rank[i] < rnk){
		ind = i;
		rnk = _rank[i];
	}
	printf(s[i] == s[ind] ? "Mike\n" : "Ann\n");
}

}