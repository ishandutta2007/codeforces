#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;

int n, a[100005];
int l[1000005], r[1000005];

int maxdiff = 1e9;
int cnt[1000005];

int main(){
	scanf("%d",&n);
	memset(l,0x3f,sizeof(l));
	memset(r,0,sizeof(r));
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
		l[a[i]] = min(l[a[i]], i);
		r[a[i]] = max(r[a[i]], i);
	}
	int maxv = *max_element(cnt, cnt + 1000005);

	for(int i=1; i<=1000000; i++){
		if(cnt[i] == maxv && l[i] <= r[i]){
			maxdiff =min(maxdiff, r[i] - l[i]);
		}
	}
	for(int i=1; i<=1000000; i++){
		if(r[i] - l[i] == maxdiff && cnt[i] == maxv){
			printf("%d %d",l[i]+1, r[i]+1);
			return 0;
		}
	}
}