#include<stdio.h>
#include<vector>
#include<utility>
#include<cstring>

const long long int MAXNUM = 1000000000000000;
const long long int MINNUM = -MAXNUM;
const int hash = 65537;
int n, k, c[100010];
long long inc[100010], ayy[100010];
int check[hash+10] = {0};
std::vector<std::pair<long long int, int>> v[hash+10];
long long int ans = 0;

int posmod(long long int a, int b)
{
	return ((a%b)+b)%b;
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 0; i<n; i++)
		scanf("%d", &c[i]);
	inc[0] = 0;
	for(int i = 0; i<n; i++)
		inc[i+1] = inc[i]+c[i];
	long long int kl = 1;
	while(kl >= MINNUM && kl <= MAXNUM){
		for(int i = 0; i<n+1; i++)
			ayy[i] = inc[i];
		memset(check, 0, sizeof(int)*(hash+10));
		for(int i = 0; i<hash+10; i++) v[i].clear();
		for(int i = 0; i<=n; i++){
			int hashkey = posmod(ayy[i],hash);
			int key2 = posmod(hashkey-kl, hash);
			if(check[key2] == 1){
				for(int j = 0; j<v[key2].size(); j++){
					if(ayy[i]-v[key2][j].first == kl)
						ans += v[key2][j].second;
				}
			}
			if(check[hashkey] == 0){
				check[hashkey] = 1;
				v[hashkey].push_back(std::make_pair(ayy[i], 1));
			}
			else{
				int flag = 1;
				for(int j = 0; j<v[hashkey].size(); j++){
					if(v[hashkey][j].first == ayy[i]){
						v[hashkey][j].second = v[hashkey][j].second + 1;
						flag = 0;
					}
				}
				if(flag == 1)
					v[hashkey].push_back(std::make_pair(ayy[i], 1));
			}
		}
		kl *= k;
		if(kl==1) break;
	}
	printf("%I64d", ans);
	return 0;
}