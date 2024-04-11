#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

string s[6] = {"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+"};

int main(){
	int k;
	cin >> k;
	int p = 0;
	while(k){
		for(int j=0; j<6; j++){
			if(k > 0 && s[j][p] == '#'){
				s[j][p] = 'O';
				k--;
			}
		}
		p++;
	}
	for(int i=0; i<6; i++) cout << s[i] << endl;
}