#include<bits/stdc++.h>
#define MAXN 3000010
#define MAXM 200010
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return a;
}

struct thing{
	int w , p , l , r , ind;
}now;
vector < thing > v[MAXN];
vector < int > anss;
int maxPri[MAXN] , last[MAXM] , k[MAXN] , cnt[MAXN] , ans[MAXN] , maxN = -1 , maxDir;
bool haveEnd[MAXN];

void out(int dir){
	while(dir != -1){
		anss.push_back(v[maxDir][dir].ind);
		dir = last[dir];
	}
	for(int i = anss.size() - 1 ; i >= 0 ; i--)
		printf("%d " , anss[i]);
}

int main(){
	int N = read();
	for(int i = 1 ; i <= N ; i++){
		now.w = read();
		now.p = read();
		now.l = read();
		now.r = read();
		now.ind = i;
		if(cnt[now.p + now.l + now.r] || now.l == 0){
			cnt[now.p + now.l + now.r]++;
			v[now.p + now.l + now.r].push_back(now);
			if(now.r == 0)
				haveEnd[now.p + now.l + now.r] = 1;
		}
	}
	memset(maxPri , -0x3f , sizeof(maxPri));
	maxPri[0] = 0;
	for(int i = 0 ; i <= 3000000 ; i++)
		if(cnt[i] && haveEnd[i]){
			for(int j = 0 ; j < cnt[i] ; j++)
				maxPri[v[i][j].l + v[i][j].p] = max(maxPri[v[i][j].l + v[i][j].p] , maxPri[v[i][j].l] + v[i][j].w);
			if(maxN < maxPri[i]){
				maxN = maxPri[i];
				maxDir = i;
			}
			for(int j = 0 ; j < cnt[i] ; j++)
				maxPri[v[i][j].l + v[i][j].p] = -0x3f3f3f3f;
		}
	memset(last , -1 , sizeof(last));
	memset(k , -1 , sizeof(k));
	for(int j = 0 ; j < cnt[maxDir] ; j++)
		if(maxPri[v[maxDir][j].l + v[maxDir][j].p] < maxPri[v[maxDir][j].l] + v[maxDir][j].w){
			maxPri[v[maxDir][j].l + v[maxDir][j].p] = maxPri[v[maxDir][j].l] + v[maxDir][j].w;
			last[j] = k[v[maxDir][j].l];
			k[v[maxDir][j].l + v[maxDir][j].p] = j;
			ans[v[maxDir][j].l + v[maxDir][j].p] = ans[v[maxDir][j].l] + 1;
		}
    printf("%d\n" , ans[maxDir]);
	out(k[maxDir]);
	return 0;
}