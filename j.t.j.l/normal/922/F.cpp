#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 2e6 + 10;
const int MM = 1e9 + 7;
const ll INF = 1ll << 60;

int n, K;

int cnt[MAXN], res[MAXN];

int main(){
    scanf("%d%d", &n, &K);
	int KK = K;
    ll sum = 0;
    for (int i = 1; i <= n; i++){
        sum += n / i - 1;
    }
    if (sum < K) {
        puts("No");
        return 0;
    }
	
	if (n <= 21){
		int o = 1 << n;
		for (int x = 0; x < o; x++){
			vector<int> f;
			for (int j = 0; j < n; j++)
				if ((x >> j) & 1)
					f.push_back(j + 1);
			int ans = 0;
			for (int i = 0; i < f.size(); i++)
				for (int j = 0; j < i; j++)
					if (f[i] % f[j] == 0)
						ans++;
			if (ans == K){
				puts("Yes");
				printf("%d\n", f.size());
				for (int i = 0; i < f.size(); i++)
					printf("%d%c", f[i], " \n"[i + 1 == f.size()]);
				return 0;
			}
		}
		puts("No");
		return 0;
	}
	
	//cout << "!!" << endl;
    for (int i = 1; i <= n / 2; i++){
        for (int j = 2 * i; j <= n / 2; j += i){
            cnt[j]++;
        }
    }
	//cout << "!!" << endl;
    vector<int> ans;
	int flag = 0;
    for (int i = 1; i <= n / 2; i++){
		if (K >= cnt[i]){
			K -= cnt[i];
			ans.push_back(i);
		}
		else{
			flag = 1;
			for (int ii = 1; ii < i; ii++){
				for (int j = 2 * ii; j <= n; j += ii){
					cnt[j]++;
				}
			}
			break;
		}
	}
	if (!flag){			
		for (int i = 1; i <= n / 2; i++){
			for (int j = 2 * i; j <= n; j += i){
				cnt[j]++;
			}
		}
	}
	//cout << "!!" << endl;
	int m = n / 2 + 1;
	vector<PII> g;
	for (int i = m; i <= n; i++)
		g.push_back(PII(cnt[i], i));
	sort(g.begin(), g.end());
	/*
	cout << "!!" << endl;
	cout << K << endl;
	for (auto &x : g)
		cout << x.first << ' ' << x.second << endl;
	return 0;
	*/
	reverse(g.begin(), g.end());
	for (auto &x : g)
		if (K >= x.first){
			K -= x.first;
			ans.push_back(x.second);
		}
	//cout << "!! " << K << ' ' << endl;
	vector<int> pm;
	for (int i = 1; i <= n / 2; i++)
		if (cnt[i] == 1)
			pm.push_back(i);
	srand(time(NULL));
	int umi = 0;
	/*
	while (K != 0){
		//assert(K == 1);
		umi++;
		ans.clear();
		int p = pm[rand() % pm.size()];
		for (int i = p + p; i <= n; i += p)
			cnt[i]--;
		K = KK;
		for (int i = 1; i <= n / 2; i++)
			if (i != p){
				ans.push_back(i);
				K -= cnt[i];
			}
		g.clear();			
		for (int i = m; i <= n; i++)
			g.push_back(PII(cnt[i], i));
		sort(g.begin(), g.end());
		reverse(g.begin(), g.end());
		for (auto &x : g)
			if (K >= x.first){
				K -= x.first;
				ans.push_back(x.second);
			}
		for (int i = p + p; i <= n; i += p)
			cnt[i]++;
		//cout << K << endl;
	}*/
	puts("Yes");
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++){
		printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
	}
	/*
	sort(ans.begin(), ans.end());
	for (int i = 1; i <= n; i++)
		res[i] = 0;
	for (auto &x : ans) res[x] = 1;
	int ret = 0;
	for (int i = 1; i <= n; i++)
		if (res[i])
			for (int j = i + i; j <= n; j += i)
				if (res[j])
					ret++;
	cout << ret << ' ' << KK << ' ' << umi << endl;
	*/
    return 0;
}