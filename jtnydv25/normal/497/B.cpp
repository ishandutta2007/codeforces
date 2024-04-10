#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int a[N];
int pref1[N], pref2[N];
vector<pair<int, int>> sol;
inline int getNext(int i, int n, int t){
	if(max(pref2[n] - pref2[i - 1], pref1[n] - pref1[i - 1]) < t) return -1;
	int lo = i, hi = n;
	while(lo < hi){
		int mid = (lo + hi) >> 1;
		if(max(pref2[mid] - pref2[i - 1], pref1[mid] - pref1[i - 1]) >= t) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

int cnt1, cnt2;
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		pref1[i] = pref1[i - 1] + (a[i] == 1);
		pref2[i] = pref2[i - 1] + (a[i] == 2);
	}

	for(int t = 1; t <= n; t++){
		int curr = 1;
		cnt1 = cnt2 = 0;
		bool flag = 0;
		int lstwin = 0;
		while(curr > 0 && curr <= n){
			int lst = getNext(curr, n, t);
			if(lst < 0){
				flag = 1;
				break;
			}
			if(pref1[lst] - pref1[curr - 1] == t){
				if(a[lst] != 1){
					assert(0);	
					flag = 1;
					break;
				}
				cnt1++;
				lstwin = 1;
			}
			else if(pref2[lst] - pref2[curr - 1] == t){
				if(a[lst] != 2){
					assert(0);
					flag = 1;
					break;
				}
				cnt2++;
				lstwin = 2;
			}
			curr = lst + 1;
		}

		if(!flag){
			if((cnt1 > cnt2 && lstwin == 1) || ((cnt1 < cnt2) && lstwin == 2)) {
				sol.push_back({max(cnt1, cnt2), t});
			}
		}
	}
	sort(sol.begin(), sol.end());
	printf("%d\n", (int) sol.size());
	for(auto it : sol) printf("%d %d\n", it.first, it.second);
}