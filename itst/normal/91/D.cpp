#include<bits/stdc++.h>
#define P pair < deque < int > , deque < int > > 
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

const int MAXN = 100010;
int num[MAXN] , N , cnt;
deque < P > ans , ans2 , ans3;
deque < int > pre , pre2;

inline void search(int x){
	pre.clear();
	pre.push_back(x);
	int p = num[x];
	while(p != x && pre.size() < 5){
		pre.push_back(p);
		p = num[p];
	}
	pre2 = pre;
	pre2.push_back(pre2.front());
	pre2.pop_front();
	int k = num[pre[pre.size() - 1]];
	for(int i = pre.size() - 2 ; i >= 0 ; --i)
		num[pre2[i]] = num[pre[i]];
	num[pre2[pre.size() - 1]] = k;
	if(pre.size() == 2)
		ans2.push_back(P(pre , pre2));
	else
		if(pre.size() == 3)
			ans3.push_back(P(pre , pre2));
		else
			ans.push_back(P(pre , pre2));
}

int main(){
	N = read();
	for(int i = 1 ; i <= N ; ++i)
		num[i] = read();
	for(int i = 1 ; i <= N ; ++i)
		while(num[i] != i)
			search(i);
	while(ans2.size() && ans3.size()){
		P v1 = ans2.front() , v2 = ans3.front();
		v1.first.insert(v1.first.end() , v2.first.begin() , v2.first.end());
		v1.second.insert(v1.second.end() , v2.second.begin() , v2.second.end());
		ans.push_back(v1);
		ans2.pop_front();
		ans3.pop_front();
	}
	while(ans2.size() >= 2){
		P v1 = ans2.front() , v2 = ans2.back();
		v1.first.insert(v1.first.end() , v2.first.begin() , v2.first.end());
		v1.second.insert(v1.second.end() , v2.second.begin() , v2.second.end());
		ans.push_back(v1);
		ans2.pop_front();
		ans2.pop_back();
	}
	while(ans2.size()){
		ans.push_back(ans2.front());
		ans2.pop_front();
	}
	while(ans3.size() >= 3){
		P v1 = ans3.front();
		ans3.pop_front();
		P v2 = ans3.front();
		ans3.pop_front();
		P v3 = ans3.front();
		ans3.pop_front();
		v1.first.push_back(v3.first[0]);
		v1.first.push_back(v3.first[1]);
		v1.second.push_back(v3.first[1]);
		v1.second.push_back(v3.first[0]);
		ans.push_back(v1);
		v2.first.push_back(v3.first[0]);
		v2.first.push_back(v3.first[2]);
		v2.second.push_back(v3.first[2]);
		v2.second.push_back(v3.first[0]);
		ans.push_back(v2);
	}
	while(ans3.size()){
		ans.push_back(ans3.front());
		ans3.pop_front();
	}
	printf("%d\n" , ans.size());
	for(int i = 0 ; i < ans.size() ; ++i){
		P v = ans[i];
		printf("%d\n" , v.first.size());
		for(int j = 0 ; j < v.first.size() ; ++j)
			printf("%d " , v.first[j]);
		puts("");
		for(int j = 0 ; j < v.second.size() ; ++j)
			printf("%d " , v.second[j]);
		puts("");
	}
	return 0;
}