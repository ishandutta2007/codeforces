#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pi;

int n, a[100005];
int cnt[100005];
int vis[100005];
int your_mothers_fucking_timestamp[100005];
int val[100005];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		int p = a[i], piv = 0;
		vector<int> v;
		while(p){
			if(your_mothers_fucking_timestamp[p] != i){
				your_mothers_fucking_timestamp[p] = i;
				val[p] = piv;
				v.push_back(p);
			}
			int piv2 = piv;
			for(int j=2*p; j<=100000; j<<=1){
				piv2++;
				if(your_mothers_fucking_timestamp[j] != i){
					your_mothers_fucking_timestamp[j] = i;
					val[j] = piv2;
					v.push_back(j);
				}
				else break;
			}
			piv++;
			p >>= 1;
		}
		for(auto &i : v){
			vis[i]++;
			cnt[i] += val[i];
		}
	}
	int ret = 1e9;
	for(int i=1; i<=100000; i++){
		if(vis[i] == n) ret = min(ret, cnt[i]);
	}
	printf("%d",ret);
}