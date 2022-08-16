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

const int N = 1e6+10;
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
int floorlog[N];
int RMQ[logN][N];

inline int lcp(int i,int j,int n) // lcp of suffix at indices i and j in suffix array
{		if(i > j) swap(i, j);
        if(j>=n)
                return -1;
        if(i==j)
                return n - pos[i];
        j--;
        int k = floorlog[j- i + 1];
        assert(i+(1<<k)<=j+1);
        return min(RMQ[k][i],RMQ[k][j-(1<<k)+1]);
}
int n;
char s[N];
char t[N];

vector<int> positions[2];

inline int get_index(int len_this, int len_other, int ind, int p){
	return ind * len_this + (p - ind) * len_other;
}

bool chk(vector<int> & v, int len_this, int len_other){
	if(v.size() <= 1) return true;
	int p1 = _rank[get_index(len_this, len_other, 0, v[0])];
	for(int i = 1; i < v.size(); i++){
		int p = _rank[get_index(len_this, len_other, i, v[i])];
		if(lcp(p1, p, n) < len_this) return 0;
	}
	return 1;
}

int main()
{
    for(int i = 0; (1 << i) < N; i++)
    	for(int j = (1 << i); j < (1 << (i + 1)) && j < N; j++)
    		floorlog[j] = i;
    
    scanf("%s", s);
    scanf("%s", t);
    n = strlen(t);
    int m = strlen(s);
    for(int i = 0;i<n;i++)
        str[i] = t[i] - 'a';
    suffixSort(n);
    getHeight(n);
    for(int i = n-1;i>=0;i--)
    {
            RMQ[0][i] = height[i];    
            for(int j = 1;i+(1<<j)<=n;j++)
                    RMQ[j][i] = min(RMQ[j-1][i],RMQ[j-1][i+(1<<(j-1))]);
    }
    for(int i = 0; i < m; i++) positions[s[i] - '0'].push_back(i);

    int ind = 0; if(positions[0].size() < positions[1].size()) ind = 1;

	vector<int> X = positions[ind], Y = positions[ind ^ 1];

	int num0 = X.size(), num1 = Y.size();

	int ans = 0;

	for(int l0 = 1; num0 * l0 <= n; l0++){
		if((n - num0 * l0) % num1 != 0) continue;
		int l1 = (n - num0 * l0) / num1;
		if(l1 == 0 || (l0 == l1 && lcp(_rank[get_index(l0, l1, 0, X[0])], _rank[get_index(l1, l0, 0, Y[0])], n) >= l0))
		 continue;
		bool ok1 = chk(X, l0, l1), ok2 = chk(Y, l1, l0);
		// trace(l0, l1, ok1, ok2, l0, l1);
		ans += (ok1 && ok2);
	}
	printf("%d\n", ans);
}