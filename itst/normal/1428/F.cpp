#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll sum , ans; int N , pot[500003]; string s;

int main(){
	pot[0] = 1; cin >> N >> s;
	for(int i = 0 ; i < s.size() ; ++i)
		if(s[i] == '0'){ans += sum; ++pot[0];}
		else{
			int p = i; while(p < s.size() && s[p] == '1') ++p;
			for(int j = 0 ; j < p - i ; ++j){pot[j + 1] += pot[j]; sum += pot[j]; pot[j] = 0; ans += sum + j * (j + 1ll) / 2;}
			for(int j = p - i - 1 ; ~j ; --j){pot[j] = 1; sum += j;}
			i = p - 1;
		}
	cout << ans; return 0;
}