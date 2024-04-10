#include<bits/stdc++.h>
using namespace std;

int N , T , K , f[300003]; string s;

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> K >> s; bool flag = 1;
		for(int i = 0 ; i < K ; ++i) f[i] = -1;
		for(int i = 0 ; i < s.size() ; ++i)
			if(s[i] == '0'){flag &= f[i % K] != 1; f[i % K] = 0;}
			else if(s[i] == '1'){flag &= f[i % K] != 0; f[i % K] = 1;}
		int sum0 = 0 , sum1 = 0;
		for(int i = 0 ; i < K ; ++i)
			if(f[i] == 0) ++sum0; else if(f[i] == 1) ++sum1;
		cout << (flag && sum0 <= K / 2 && sum1 <= K / 2 ? "YES" : "NO") << '\n';
	}
	return 0;
}