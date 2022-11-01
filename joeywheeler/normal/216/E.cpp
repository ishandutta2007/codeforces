#include <cstdio>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#ifndef ONLINE_JUDGE
#define D(x...) printf(x)
#else
#define D(x...)
#endif

typedef long long ll;
const int MAX_N = 100005;

int K, B, N;
int nums[MAX_N];

vector< pair<int,int> > left;
vector< pair<int,int> > right;

ll ways(int start, int end) {
    ll tot = 0ll;
    if(end - start <= 1) {
        if(nums[start] % K == B && nums[start] != 0) {
            tot = 1ll;
        }
    } else {
        int pivot = (start + end)/2;
        tot += ways(start, pivot);
        tot += ways(pivot, end);
        
        left.clear();
        right.clear();
        
        int cumul = 0;
        bool nonZero = false; 
        for(int i=pivot-1;i>=start;i--) {
            if(nums[i] != 0) {
                nonZero = true;
            }
            cumul = (cumul + nums[i])%K;
            left.push_back(make_pair((B-cumul+K)%K, nonZero));
//            D("added %d to left\n",left[left.size()-1]);
        }
        
        cumul = 0;
        nonZero = false; 
        for(int i=pivot;i<end;i++) {
            if(nums[i] != 0) {
                nonZero = true;
            }
            cumul = (cumul + nums[i])%K;
            right.push_back(make_pair(cumul,nonZero));
  //          D("added %d to right\n",cumul);
        }
        
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        
        int upto = 0;
        int cur = 0;
        ll consec = 0ll;
        for(int i=0;i<left.size();i++) {
            if(cur != left[i].first) {
                consec = 0ll;
            }
            
            while(upto < right.size() && right[upto].first <= left[i].first) {
                if(right[upto].first == left[i].first) {
                    consec++;
                }
                cur = right[upto].first;
                upto++;
            }
            
            if(cur == left[i].first) {
//                D("added %I64d possibilities for %d\n",consec,left[i]);
                tot += consec;
            }
        }
        
        if(B == 0) {
            ll le = 0ll;
            ll ri = 0ll;
            for(int i=0;i<left.size();i++) {
                if(left[i].first == 0 && !left[i].second) {
                    le++;
                }
            }
            
            for(int i=0;i<right.size();i++) {
                if(right[i].first == 0 && !right[i].second) {
                    ri++;
                }
            }
            tot -= le * ri;
        }
    }
    D("ways(%d,%d) = %I64d\n",start,end,tot);
    return tot;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("e.in","r",stdin);
    freopen("e.out","w",stdout);
#endif

    scanf("%d %d %d",&K,&B,&N);
    K--;
    
    for(int i=0;i<N;i++) {
        scanf("%d",&nums[i]);
    }
    
    if(B == 0) {
        ll tot = 0ll;
        ll num = 0ll;
        for(int i=0;i<N;i++) {
            if(nums[i] == 0) {
                num++;
            } else {
                tot += (num*(num+1ll))/2ll;
                num = 0ll;
            }
        }
        tot += (num*(num+1ll))/2ll;
        printf("%I64d\n",tot);
    } else {
        B %= K;
        printf("%I64d\n",ways(0,N));
    }
    
    return 0;
}