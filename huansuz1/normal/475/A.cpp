#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <stack>


using namespace std;

int n,z;
char a[123][123]=
    {"+------------------------+",
	"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
	"|#.#.#.#.#.#.#.#.#.#.#.|.|",
	"|#.......................|",
	"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
	"+------------------------+"};

int main(){
	cin>>n;
	for (int i=0; i<27; i++){
		for (int j=0; j<6; j++){
			if (z==n) break;         
			if (a[j][i]=='#') {a[j][i]='O';z++;}
	   
	   }
	}
	for (int i=0; i<6; i++){
		for (int j=0; j<26; j++)
			cout<<a[i][j];
			if (i==1||i==4) cout<<')';
			cout<<endl;

	}

	return 0;
}