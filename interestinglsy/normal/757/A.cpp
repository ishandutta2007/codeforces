#include <iostream>
#include <string.h>
#include <cmath>
#define uint unsigned int
using namespace std;

char c;
uint data[2560];

int main(){
	memset(data,0,sizeof(data));
	
	while(cin >> c)
		data[c-'A']++;
	
	uint ans = 0;
	string b = "Bulbasaur";
	uint lenb = b.length();
	bool exit = 0;
	while(1){
		for(uint i = 0;i < lenb;i++)
			if(data[b[i]-'A'] == 0){exit = 1;break;}
			else data[b[i]-'A']--;
		if(exit) break;
		ans++;
	}
	 
	cout << ans << endl;
	
	return 0;
}