#include<bits/stdc++.h>
using namespace std;

int T , N , M; string str;

int main(){
	for(cin >> T ; T ; --T){
		cin >> N >> M >> str;
		for(int i = 0 ; i < M ; ++i){
			string str1 = str;
			for(int j = 0 ; j < str1.size() ; ++j)
				if(str1[j] == '0'){
					bool flg1 = j && str[j - 1] == '1' , flg2 = j + 1 != str1.size() && str[j + 1] == '1';
					str1[j] = '0' + (flg1 ^ flg2);
				}
			if(str == str1) break;
			str = str1;
		}
		cout << str << endl;
	}
	return 0;
}