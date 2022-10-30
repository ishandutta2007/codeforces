#include<bits/stdc++.h>
#define ll long long
#define MAXN 200010
using namespace std;

inline ll read(){
	ll a = 0;
	bool f = 0;
	char c = getchar();
	while(!isdigit(c))	{
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

int num[MAXN] , Tree[MAXN] , dir[MAXN] , cntLSH;
ll sum[MAXN] , sorted[MAXN];
map < ll , int > lsh;

inline int lowbit(int a){
	return a & -a;
}

inline void add(int a){
	while(a <= cntLSH){
		Tree[a]++;
		a += lowbit(a);
	}
}

inline int getSum(int a){
	int sum = 0;
	while(a){
		sum += Tree[a];
		a -= lowbit(a);
	}
	return sum;
}

bool cmp(ll a , ll b){
	return a > b;
}

int main(){
	int N = read();
	ll T = read() , ans = 0;
	for(int i = 1 ; i <= N ; i++)
		sum[i] = sorted[i] = sum[i - 1] + (num[i] = read());
	sort(sorted + 1 , sorted + N + 2 , cmp);
	int d = 0 , cnt = 0;
	for(int i = 1 ; i <= N + 1 ; i++)
		if(i == 1 || sorted[i] != sorted[i - 1])
			lsh.insert(make_pair(sorted[i] , ++cntLSH));
	for(int i = 1 ; i <= N + 1 ; i++)
		if(i == 1 || sorted[i] != sorted[i - 1]){
			++cnt;
			while(d <= N && sorted[i] - sorted[d + 1] < T)
				d++;
			if(d)
				dir[cnt] = lsh.find(sorted[d])->second;
		}
	add(lsh.find(0)->second);
	for(int i = 1 ; i <= N ; i++){
		int t = lsh.find(sum[i])->second;
		ans += getSum(dir[t]);
		add(t);
	}
	cout << ans;
	return 0;
}