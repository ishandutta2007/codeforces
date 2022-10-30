#include<cstring>
#include<iostream>
using namespace std;

int main(){
	int N , pre , cnt = 1 , num = -1; cin >> N >> pre;
	for(int i = 2 ; i <= N ; ++i){
		int x; cin >> x;
		if(pre == x) ++cnt;
		else{
			if(num == -1 || num == cnt) num = cnt;
			else{puts("no"); return 0;}
			pre = x; cnt = 1;
		}
	}
	puts(num == -1 || num == cnt ? "yes" : "no");
	return 0;
}