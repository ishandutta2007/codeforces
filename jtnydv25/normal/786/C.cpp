#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
const int N = 2e6;
int lft[N],rgt[N],val[N], root[N], cnt = 0, a[N];
void push(int s, int e, int x, int pos1, int pos2){
    val[pos1] = val[pos2]+1;
    if(s==e) return;
    int mid = (s+e)/2;
    if(x<= mid){
        rgt[pos1] = rgt[pos2];
        lft[pos1] = ++cnt;
        pos2 = lft[pos2];
        pos1 = cnt;
        push(s,mid,x,pos1,pos2);
    }
    else{
        lft[pos1] = lft[pos2];
        rgt[pos1] = ++cnt;
        pos2 = rgt[pos2];
        pos1 = cnt;
        push(mid+1,e,x,pos1,pos2);
    }
}

// Number of elements lying between l and r, and having index <= i
int query(int s, int e, int l, int r, int ind){
    if(s>r || l>e) return 0;
    if(s>=l && e <= r) return val[ind];
    int mid = (s+e)>>1;
    return query(s,mid,l,r,lft[ind]) + query(mid+1,e,l,r,rgt[ind]);
}
// number of elements with indices between i and j inclusive, and values between l and r
inline int num_elements(int i, int j, int l, int r, int n){
    return query(0,n,l,r,root[j]) - query(0,n,l,r,root[i-1]);
}
map<int, int> lst;
int L[N];
int main(){
	int n;
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		L[i] = lst[a[i]];
		root[i] = ++cnt;push(0, n, L[i], root[i], root[i - 1]);
		lst[a[i]] = i;}
	int total_distinct = lst.size();		
	for(int k = 1; k <= n; k++){
		int i = 1, ans_k = 0;
		if(total_distinct <= k){
			printf("%d ", 1);
			continue;
		}
		if(2 * k >= n){
			printf("%d ",2);
			continue;
		}
		while(i <= n){
			ans_k ++;
			if(k <= 2000){
				cnt = 0; int l = i;
				while(i <= n + 1 && cnt <= k){
					if(L[i++] < l) cnt++;
				}
				i --;
				continue;
			}
			int lo = i + k - 1, hi = n;
			int sub = query(0, n, 0, i - 1, root[i - 1]);
			while(lo < hi){
				int mid = (lo + hi + 1) >> 1;
				if(query(0, n, 0, i - 1, root[mid]) - sub <= k) lo = mid;
				else hi = mid - 1;
			}
			i = min(lo, n) + 1;
		}
		printf("%d ", ans_k);
	}	
}