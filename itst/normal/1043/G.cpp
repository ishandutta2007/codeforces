#include<bits/stdc++.h>
using namespace std;

const int _ = 4e5 + 7;
int n , q , T , ans[_]; char *str;

struct sa{
	char str[_]; int sa[_] , rk[_] , tp[_] , h[_] , st[20][_]; 
	void build_sa(){
		int MX = 26;
		auto sort = [&](int p){
			static int pot[_]; memset(pot , 0 , sizeof(int) * (MX + 1));
			for(int i = 1 ; i <= n ; ++i) ++pot[rk[i]];
			for(int i = 1 ; i <= MX ; ++i) pot[i] += pot[i - 1];
			for(int i = 1 ; i <= n ; ++i) sa[++pot[rk[tp[i]] - 1]] = tp[i];
			memcpy(tp , rk , sizeof(int) * (n + 1));
			for(int i = 1 ; i <= n ; ++i) rk[sa[i]] = rk[sa[i - 1]] + (tp[sa[i]] != tp[sa[i - 1]] || tp[sa[i] + p] != tp[sa[i - 1] + p]);
			MX = rk[sa[n]];
		};
		for(int i = 1 ; i <= n ; ++i) rk[tp[i] = i] = str[i] - 'a' + 1;
		sort(0);
		for(int t = 1 ; MX != n ; t <<= 1){
			int cnt = 0; for(int i = n - t + 1 ; i <= n ; ++i) tp[++cnt] = i;
			for(int i = 1 ; i <= n ; ++i) if(sa[i] > t) tp[++cnt] = sa[i] - t;
			sort(t);
		}

		for(int i = 1 ; i <= n ; ++i){
			if(rk[i] == 1) continue;
			int t = rk[i]; h[t] = max(0 , h[rk[i - 1]] - 1);
			while(str[h[t] + i] == str[h[t] + sa[t - 1]]) ++h[t];
			st[0][t] = h[t];
		}
		for(int i = 1 ; 1 << i <= n ; ++i)
			for(int j = 1 ; j + (1 << i) - 1 <= n ; ++j)
				st[i][j] = min(st[i - 1][j] , st[i - 1][j + (1 << (i - 1))]);
	}

	int qlcp(int l , int r){
		if((l = rk[l]) > (r = rk[r])) swap(l , r);
		int t = 31 - __builtin_clz(r - l); return min(st[t][l + 1] , st[t][r - (1 << t) + 1]);
	}
}c_sa , r_sa;

struct segt{
#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
	int arr[_] , mn[_ << 2] , mrk[_ << 2]; segt(){memset(mrk , 0x3f , sizeof(mrk)); memset(mn , 0x3f , sizeof(mn));}
	void mark(int x , int l , int v){mrk[x] = min(mrk[x] , v); mn[x] = min(mn[x] , l + v);}
	void down(int x , int l , int r){if(mrk[x] != mrk[0]){mark(lch , l , mrk[x]); mark(rch , mid + 1 , mrk[x]); mrk[x] = mrk[0];}}

	void mdf(int x , int l , int r , int L , int R , int v){
		if(l >= L && r <= R) return mark(x , l , v);
		down(x , l , r); if(mid >= L) mdf(lch , l , mid , L , R , v);
		if(mid < R) mdf(rch , mid + 1 , r , L , R , v);
		mn[x] = min(mn[lch] , mn[rch]);
	}

	int qry(int x , int l , int r , int L , int R){
		if(l >= L && r <= R) return mn[x];
		int mn = 1e9; down(x , l , r); if(mid >= L) mn = qry(lch , l , mid , L , R);
		if(mid < R) mn = min(mn , qry(rch , mid + 1 , r , L , R));
		return mn;
	}

	void push(int x , int l , int r){if(l == r){arr[l] = mn[x]; return;} down(x , l , r); push(lch , l , mid); push(rch , mid + 1 , r);}
}c_segt , r_segt;

void initAA(sa &lcp_sa , sa &lcs_sa , segt &c_segt){
	for(int i = 1 ; i <= n ; ++i)
		for(int j = i ; j + i <= n ; j += i){
			int lcp = lcp_sa.qlcp(j , j + i) , lcs = lcs_sa.qlcp(n - j + 1 , n - (j + i) + 1);
			if(lcp + lcs - 1 >= i) c_segt.mdf(1 , 1 , n , j - lcs + 1 , j + lcp - 1 - i + 1 , 2 * i - 1);
		}
	c_segt.push(1 , 1 , n);
}

int sum[_][26];
void initsum(){for(int i = 1 ; i <= n ; ++i){memcpy(sum[i] , sum[i - 1] , sizeof(sum[i])); ++sum[i][str[i] - 'a'];}}

bool nprm[_];
void initprm(){for(int i = 2 ; i <= n ; ++i) for(int j = 2 * i ; j <= n ; j += i) nprm[j] = 1;}

bool s_n1(int l , int r){bool flg = 1 , vis[26] = {}; for(int i = l ; i <= r && flg ; ++i){flg = !vis[str[i] - 'a']; vis[str[i] - 'a'] = 1;} return flg;}

bool s_1(int l , int r){
	int len = r - l + 1; if(c_sa.qlcp(l , l + 1) >= len - 1) return 1;
	for(int i = 2 ; i * i <= len ; ++i)
		if(len % i == 0 && ((!nprm[len / i] && c_sa.qlcp(l , l + i) >= len - i) || (!nprm[i] && c_sa.qlcp(l , l + len / i) >= len - len / i))) return 1;
	return 0;
}

bool s_2(int l , int r){
	if(c_segt.arr[l] <= r || r_segt.arr[n - r + 1] <= n - l + 1) return 1;

	for(int i = 1 ; i <= r - l && i <= T ; ++i) if(c_sa.qlcp(l , r - i + 1) >= i) return 1;
	for(int i = c_sa.rk[l] - 1 , h = c_sa.h[i + 1] , c = 0 ; c <= T && i && h > T ; ++c , h = min(h , c_sa.h[i--]))
		if(c_sa.sa[i] >= l && c_sa.sa[i] <= r && c_sa.sa[i] + h > r) return 1;
	for(int i = c_sa.rk[l] + 1 , h = c_sa.h[i] , c = 0; c <= T && i <= n && h > T ; ++c , h = min(h , c_sa.h[++i]))
		if(c_sa.sa[i] >= l && c_sa.sa[i] <= r && c_sa.sa[i] + h > r) return 1;
	return 0;
}

bool s_3(int l , int r){
	return sum[r][str[l] - 'a'] - sum[l][str[l] - 'a'] || sum[r - 1][str[r] - 'a'] - sum[l - 1][str[r] - 'a'] || c_segt.qry(1 , 1 , n , l , r) <= r;
}

int main(){
	str = c_sa.str; scanf("%d %s" , &n , str + 1); memcpy(r_sa.str , str , sizeof(r_sa.str));
	reverse(r_sa.str + 1 , r_sa.str + n + 1); c_sa.build_sa(); r_sa.build_sa();
	initAA(c_sa , r_sa , c_segt); initAA(r_sa , c_sa , r_segt); initsum(); initprm(); T = sqrt(n) + 1;
	for(scanf("%d" , &q) ; q ; --q){
		int l , r; scanf("%d %d" , &l , &r); puts(s_n1(l , r) ? "-1" : (s_1(l , r) ? "1" : (s_2(l , r) ? "2" : (s_3(l , r) ? "3" : "4"))));
	}
	return 0;
}