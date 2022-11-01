#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)){
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

deque < int > q , ans;

signed main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	int N = read() , a = read() , cnt = 0;
	bool f = 1;
	q.push_back(a);
	for(int i = 2 ; i <= N ; ++i){
		int t = read();
		f &= t == a;
		q.push_back(t);
	}
	if(f)
		if(a)
			puts("NO");
		else{
			puts("YES");
			for(int i = 1 ; i <= N ; ++i)
				printf("%d " , 1);
		}
	else{
		while(q[q.size() - 1] <= q[q.size() - 2]){
			q.push_back(q.front());
			q.pop_front();
			++cnt;
		}
		ans.push_back(q.back());
		q.pop_back();
		q.push_front(ans.back());
		while(q.size() != 1){
			int t = ans.back() + q.back();
			if(q.size() != 1 && q[q.size() - 2] >= t)
				t += (int)ceil((q[q.size() - 2] - t + 1) * 1.0 / ans.back()) * ans.back();
			ans.push_back(t);
			q.pop_back();
		}
		reverse(ans.begin() , ans.end());
		while(cnt--){
			ans.push_front(ans.back());
			ans.pop_back();
		}
		puts("YES");
		for(int i = 1 ; i <= N ; ++i)
			printf("%lld " , ans[i - 1]);
	}
	return 0;
}