#include<bits/stdc++.h>
using namespace std;

string S , T; int trs[100003][26] , Q , pre[26][2];
bool qtrs(int x , int pos){return !pos ? 0 : (x == T.size() ? (S.size() - pos + 1) & 1 : qtrs(x + 1 , trs[pos][T[x] - 'a']));}

int main(){
	for(cin >> Q ; Q ; --Q){
		cin >> S >> T; for(int i = 0 ; i <= S.size() + 1 ; ++i){memset(trs[i] , 0 , sizeof(trs[i]));}
		memset(pre , 0 , sizeof(pre));
		for(int i = S.size() - 1 ; ~i ; --i){
			pre[S[i] - 'a'][i & 1] = i + 1;
			memcpy(trs[i] , trs[i + 2] , sizeof(trs[i])); trs[i][S[i] - 'a'] = i + 1;
		}
		puts(qtrs(1 , pre[T[0] - 'a'][0]) || qtrs(1 , pre[T[0] - 'a'][1]) ? "YES" : "NO");
	}
}