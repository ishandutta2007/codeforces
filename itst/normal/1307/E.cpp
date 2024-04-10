#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int _ = 5003 , MOD = 1e9 + 7;
int l[_] , r[_] , f[_] , h[_] , arr[_] , N , M , mx , sum;
vector < int > pot[_]; vector < pair < int , int > > moo[_];

int main(){
	scanf("%d %d" , &N , &M);
	for(int i = 1 , x ; i <= N ; ++i){scanf("%d" , &x); arr[i] = x; pot[x].push_back(i);}
	for(int i = 1 ; i <= M ; ++i){
		scanf("%d %d" , &f[i] , &h[i]);
		if(h[i] <= pot[f[i]].size())
			moo[f[i]].push_back(make_pair(pot[f[i]][h[i] - 1] , pot[f[i]][pot[f[i]].size() - h[i]]));
	}
	for(int i = 1 ; i <= N ; ++i) sort(moo[i].begin() , moo[i].end());
	for(int i = 0 ; i <= N ; ++i){
		int cnt = 0 , tms = 1;
		for(int j = 1 ; j <= N ; ++j)
			if(j == arr[i]){
				bool flg = 0; int num = 0;
				for(int k = 0 ; k < moo[j].size() ; ++k)
					if(moo[j][k].first == i) flg = 1;
					else num += moo[j][k].second > i;
				cnt += 1 + (bool)num; if(num == 0) num = 1;
				tms = 1ll * tms * flg * num % MOD;
			}
			else{
				int lft = 0 , rht = 0 , lr = 0 , num = 0;
				for(int k = 0 ; k < moo[j].size() ; ++k){
					if(moo[j][k].first < i && moo[j][k].second > i) ++lr;
					else if(moo[j][k].first < i) ++lft;
					else if(moo[j][k].second > i) ++rht;
				}
				if(lr >= 2 || (lft && (rht + lr)) || rht && lr){
					cnt += 2; tms = 1ll * tms * (1ll * lft * rht + 1ll * (lft + rht) * lr + lr * (lr - 1)) % MOD;
				}
				else if(lr || lft || rht){++cnt; tms = 1ll * tms * (lft + rht + 2 * lr) % MOD;}
			}
		if(tms && cnt > mx) sum = 0;
		if(tms && cnt >= mx){sum = (sum + tms) % MOD; mx = cnt;}
	}
	printf("%d %d\n" , mx , sum);
	return 0;
}