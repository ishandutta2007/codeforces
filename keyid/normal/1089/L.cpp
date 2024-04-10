#include <bits/stdc++.h>
using namespace std;

int k, n;
int a[100010], b[100010];

int cnt[100010];

int main(){
	scanf("%d%d", &n , &k);
	for(int i = 1 ; i <= n ; i++)
		scanf("%d" , &a[i]);
	for(int i = 1 ; i <= n ; i++)
		scanf("%d" , &b[i]);

	for(int i = 1 ; i <= n ; i++)
		cnt[a[i]]++;
    int dist_cnt = 0;
    for(int i = 1 ; i <= n ; i++)
		if(cnt[i])
			dist_cnt++;

    vector<pair<int,int>> lst;
    for(int i = 1 ; i <= n ; i++)
        lst.emplace_back(b[i], i);
    sort(lst.begin(), lst.end());

	long long ans = 0;

    for(int i = 0 ; i < lst.size() ; i++){
		if(dist_cnt == k)break;
        if(cnt[a[lst[i].second]] == 1)continue;

        //printf("take %d, cost = %d\n", lst[i].second, lst[i].first);

        cnt[a[lst[i].second]]--;
        dist_cnt++;
		ans += lst[i].first;
    }

    cout << ans << endl;
    return 0;
}