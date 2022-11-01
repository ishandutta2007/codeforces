#include<bits/stdc++.h>
//This code is written by Itst
#define ll long long
using namespace std;

const int MAXN = 5e5 + 10;
int st[MAXN] , num[MAXN] , cnt[MAXN] , N , top;

int main(){
	cin >> N;
	string s;
	int ans = 0 , cnt0 = 0;
	for(int i = 1 ; i <= N ; ++i){
		top = 0;
		cin >> s;
		for(int j = 0 ; j < s.size() ; ++j)
			if(s[j] == ')')
				if(top)
					--top;
				else
					++num[i];
			else
				++top;
		if(!top && !num[i])
			++cnt0;
		else
			if(!top || !num[i])
				if(top){
					if(cnt[top] < 0)
						++ans;
					++cnt[top];
				}
				else{
					if(cnt[num[i]] > 0)
						++ans;
					--cnt[num[i]];
				}
	}
	cout << ans + cnt0 / 2;
	return 0;
}