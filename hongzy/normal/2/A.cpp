#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int N;
map<string, int> id;
string name[1010];
int score[1010], sc2[1010] = {0}, gt[1010], cnt;

string si[1010]; 
int ti[1010] = {0};

int ID(string s) {
	if(!id[s]) {
		++ cnt;
		name[cnt] = s;
		id[s] = cnt;
	}
	return id[s];
}

int main() {
	int t, _d, ans = -1e9, ans2 = 1e9, ans3 = 0;
	char s[101];
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%s %d", s, &t);
		_d = ID(string(s));
		si[i] = string(s); ti[i] = t;
		score[_d] += t;
	}
	for(int i=1; i<=cnt; i++)
		if(score[i] > ans)
			ans = score[ans3 = i]; 
	for(int i=1; i<=N; i++) {
		_d = ID(si[i]); sc2[_d] += ti[i];
		if(sc2[_d] >= ans && !gt[_d]) gt[_d] = i;
	}
	for(int i=1; i<=cnt; i++)
		if(ans == score[i] && gt[i] < ans2)
			ans2 = gt[ans3 = i];
	printf("%s\n", name[ans3].c_str());
	return 0;
}