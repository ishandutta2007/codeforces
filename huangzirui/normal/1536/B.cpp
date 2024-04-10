/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.18.10:24
*Problem       :  CF1536B
************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
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
	const int maxn = 1e2+10;
	string a,Null;
	int n;
	inline void main() {
		read(n);
		cin>>a;
		queue< pair<string,int> > q;
		q.push({Null,0});
		while (233) {
			pair<string,int> tmp = q.front();q.pop();
			string x = tmp.first;
			int pos = tmp.second;
			x.resize(pos+1);
			for (int i = 0;i < 26;++i) {
				x[pos] = (char)('a'+i);
				if (a.find(x) == string :: npos)return cout<<x<<endl,void();
				q.push({x,pos+1});
			}
		}
		return;
	}
}

int main() {
#ifdef demonlover
	freopen("CF1536B.in","r",stdin);
	freopen("CF1536B.out","w",stdout);
#endif
	int T;read(T);
	while (T--)run :: main();
	return 0;
}