#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

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

inline int lcp(int i,int j,int n) // lcp of suffix at indices i and j in suffix array
{
    if(i>j||j>=n)
        return 0;
    if(i==j)
        return n - pos[i];
    j--;
    int k = ceillog[j-i+2] - 1;
    assert(i+(1<<k)<=j+1);
    return min(RMQ[k][i],RMQ[k][j-(1<<k)+1]);
}

const int B = 1005;

inline int getFreq(int i, int h, int n){
    int lo = i, hi = n - 1;
    while(lo < hi){
      int mid = (lo + hi + 1) >> 1;
      if(lcp(i, mid, n) >= h){
            lo = mid;
      }
      else hi = mid - 1;
    }

    return lo - i + 1;
}

long long get(int n){
    return (n * 1ll * (n + 1)) /2 ;
}
int main()
{
        cin.tie(NULL);
        ios_base::sync_with_stdio(0);
    ceillog[1]=0;
    int k;
    for(k=1;(1<<k)<5*N;k++)
        for(int i = (1<<(k-1)) + 1;i<=(1<<k);i++)
            ceillog[i] = k;
    for(int i = (1<<k);i<5*N;i++)                
        ceillog[i] = k+1;    
    
    string s = "";
    cin>>s;
    int n = s.length();
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
    long long ans = 0;
    int prev = 0;
    for(int i = 0;i<n;i++)
    {
        // Find least h, such that getFreq(i, h, n) is <= B
        int h = prev + 1;
        for(h = prev+1;h<=height[i];h++)
        {
            int f = getFreq(i, h, n);
            if(f < B)
                break;
            ans += (f * 1ll * (f + 1)) / 2;
        }

        int lmin = max(prev,height[i]);
        ans += max(0,n-pos[i]-lmin);

        if(h <= height[i]){
            int mn = height[i];
            for(int j = i + 1; j - i + 1 < B && j < n; j++){
                if(height[j] < mn){
                    // cerr << i << ", " << mn << ", cnt = " << mn - height[j] << endl;
                    ans += max(0, (mn - max(prev, height[j]))) * 1ll * get(j - i + 1);
                    mn = height[j];
                }
            }
        }
        prev = height[i];
    }
    cout<<ans<<endl;
}