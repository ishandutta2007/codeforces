/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.20.15:48
*Problem       :  CF1493C
************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <ctime>
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;
#define DEBUG(x) cout << #x << " = " << x << "\n"
template <typename T>
inline bool read(T &x) {
	int f = 1,c = getchar();x = 0;
	while (!isdigit(c)) {if (c == 45)f = -1;c = getchar();}
	while (isdigit(c))x = (x<<3)+(x<<1)+(c^48),c = getchar();
	return x *= f,true;
}
template <typename T,typename... Args>
inline bool read(T &x,Args &...args) {
	return read(x) && read(args...);
}

namespace run {
	const int maxn = 1e5+10;
	int cnt[26];
	int n,k;
	char str[maxn];
	vector<char> v;
	inline void main() {
		read(n,k);
		scanf("%s",str+1);
		if (n%k)return puts("-1"),void();
		memset(cnt,0,sizeof(cnt));
		for (int i = 1;i <= n;++i)if ((++cnt[str[i]-'a']) >= k)cnt[str[i]-'a'] -= k;
		int sum = 0;
		for (int i = 0;i < 26;++i)if (cnt[i])sum += k-cnt[i];
		if (!sum)return puts(str+1),void();
		for (int i = n;i;--i) {
			bool flg = false;
			if (cnt[str[i]-'a'])sum -= k-cnt[str[i]-'a'];
			if ((--cnt[str[i]-'a']) < 0)cnt[str[i]-'a'] += k;
			if (cnt[str[i]-'a'])sum += k-cnt[str[i]-'a'];
			for (int j = str[i]-'a'+1;j < 26;++j) {
				if (cnt[j])sum -= k-cnt[j];
				if ((++cnt[j]) >= k)cnt[j] -= k;
				if (cnt[j])sum += k-cnt[j];
				if (sum <= n-i) {
					flg = true;
					for (int t = 1;t < i;++t)putchar(str[t]);
					putchar(j+'a');
					v.clear();
					for (int t = 0;t < 26;++t)
						if (cnt[t])
							for (int w = cnt[t]+1;w <= k;++w)
								v.push_back(t+'a');
					for (int t = (int)v.size();t < n-i;++t)putchar('a');
					for (auto t : v)putchar(t);
					break;
				}
				if (cnt[j])sum -= k-cnt[j];
				if ((--cnt[j]) < 0)cnt[j] += k;
				if (cnt[j])sum += k-cnt[j];
			}
			if (flg)break;
		}
		puts("");
		return;
	}
}

int main() {
#ifdef demonlover
	freopen("CF1493C.in","r",stdin);
	freopen("CF1493C.out","w",stdout);
#endif
	int T;read(T);
	while (T--)run :: main();
	return 0;
}