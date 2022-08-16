#include <bits/stdc++.h>
using namespace std;
 
const int N = 4e5+10;
int str[N]; //input
int _rank[N], pos[N]; //output
int cnt[N], _next[N]; //internal
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
      cnt[i] = 0;
      for (int j = i; j < _next[i]; ++j){
        _rank[pos[j]] = i;
      }
    }
  
    cnt[_rank[n - h]]++;
    b2h[_rank[n - h]] = true;
    for (int i = 0; i < n; i = _next[i]){
      for (int j = i; j < _next[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0){
          int head = _rank[s];
          _rank[s] = head + cnt[head]++;
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
    if(i>j||j>=n)
        return -1;
    if(i==j)
        return n - pos[i];
    j--;
    int k = ceillog[j-i+2] - 1;
    assert(i+(1<<k)<=j+1);
    return min(RMQ[k][i],RMQ[k][j-(1<<k)+1]);
}


int root[N];

int lft[N * 20],rgt[N * 20],val[N * 20], CNT = 0;
void push(int s, int e, int x, int pos1, int pos2)
{
    val[pos1] = val[pos2]+1;
    if(s==e)
        return;
    int mid = (s+e)/2;
    if(x<= mid)
    {
        rgt[pos1] = rgt[pos2];
        lft[pos1] = ++CNT;
        pos2 = lft[pos2];
        pos1 = CNT;
        push(s,mid,x,pos1,pos2);
    }
    else
    {
        lft[pos1] = lft[pos2];
        rgt[pos1] = ++CNT;
        pos2 = rgt[pos2];
        pos1 = CNT;
        push(mid+1,e,x,pos1,pos2);
    }
}

int n;
inline int get(int s, int e, int p, int l, int r){
	if(l > r) return 0;
	if(!pos) return 0;
	if(l > e ||s > r) return 0;
	if(s >= l && e <= r) return val[p];
	int mid = (s + e) / 2;
	return get(s, mid, lft[p], l, r) + get(mid + 1, e, rgt[p], l, r);
}

inline int get(int i, int j, int l, int r){
	if(i > j) return 0;
	return get(0, n, root[j], l, r) - ((i <= 0) ? 0 : get(0, n, root[i - 1], l, r));
}


int  L[N], R[N];
char s[N];
bool done[N];
int st[N], en[N];
int main(){
	ceillog[1]=0;
    int k;
    for(k=1;(1<<k)<5*N;k++)
        for(int i = (1<<(k-1)) + 1;i<=(1<<k);i++)
            ceillog[i] = k;
    for(int i = (1<<k);i<5*N;i++)        
    ceillog[i] = k+1;
	int q;
	cin >> n >> q;
	int curr = 0;
	for(int i = 0; i < n; i++){
		scanf("%s", s + curr);
		L[i] = curr;
		for(; s[curr]; curr++){}
		s[curr++]  = '#';
		R[i] = curr - 2;
	}
	n = curr;

	for(int i = 0; i <n; i++)
		str[i] = s[i] - 'a';

	suffixSort(n);
	getHeight(n);

	for(int i = 1; i <= n; i++){
		root[i] = ++CNT;
		push(0, n, pos[i - 1], root[i], root[i - 1]);
	}
	for(int i = n-1;i>=0;i--){
        RMQ[0][i] = height[i];  
        for(int j = 1;i+(1<<j)<=n;j++)
            RMQ[j][i] = min(RMQ[j-1][i],RMQ[j-1][i+(1<<(j-1))]);
    }
    while(q--){
    	int l, r, k;
    	scanf("%d %d %d", &l, &r, &k);
    	l--; r--; k--;
    	int p = _rank[L[k]];
    	int len = R[k] - L[k] + 1;
    	if(!done[k]){
	    	int lo = p, hi = n - 1;
	    	while(lo < hi){
	    		int mid = (lo + hi + 1) >> 1;
	    		if(lcp(p, mid, n) >= len)
	    			lo = mid;
	    		else hi = mid - 1;
	    	}
	    	int i = lo;
	    	lo = 0, hi = p;
	    	while(lo < hi){
	    		int mid = (lo + hi) >> 1;
	    		if(lcp(mid, i, n) >= len)
	    			hi = mid;
	    		else
	    			lo = mid + 1;;
	    	}
	    	int j = lo;
	    	swap(i, j);
	    	st[k] = i; en[k] = j;
	    	done[k] = 1;
	    }
	    int i = st[k], j = en[k];
	    l = L[l];
    	r = R[r] - len + 1;  
    	if(r < l){
    		printf("%d\n", 0);
    		continue;
    	}
    	printf("%d\n", get(i + 1, j + 1, l, r));
    }
}