#include <iostream>
#include <string.h>
#include <cmath>
#include <sstream>
#define ms(a) memset(a,0,sizeof(a))
using namespace std;

#define MAXN 2000000
int pai[MAXN+100];
void get_prime(){
	bool is_prime[MAXN+100];
	for(int i = 2;i <= MAXN;i++) is_prime[i] = 1;
	for(int i = 2;i <= sqrt(MAXN);i++)
		if(is_prime[i])
			for(int pos = i+i;pos <= MAXN;pos += i)
				if(pos <= MAXN  &&  pos >= 0)
					is_prime[pos] = 0;
	int nowp = 0;
	for(int i = 2;i <= MAXN;i++){
		if(is_prime[i])
			nowp++;
		pai[i] = nowp;
	}
	pai[1] = 0;
	/*
	for(int i = 1;i <= 100;i++)
		if(is_prime[i])
			cout << i << " ";
	cout << endl;
	*/
	//cout << pai[100] << endl;;
}

int hw[MAXN+100];
bool is_hw(int a){
	char s[20];
	sprintf(s,"%d",a);
	int l = 0,r = strlen(s)-1;
	while(l < r){
		if(s[l] != s[r]) return 0;
		l++; r--;
	}
	return 1;
}
void get_hw(){
	int now_hw = 0;
	for(int i = 1;i <= MAXN;i++){
		//if(i % 100000 == 0) cout << i << endl;
		if(is_hw(i))
			now_hw++;
		hw[i] = now_hw;
	}
}

int main(){
	get_hw();
	get_prime();
	
	int p,q;
	cin >> p >> q;
	for(int i = MAXN;i >= 1;i--)
		if(q * pai[i] <= p * hw[i]){
			cout << i << endl;
			return 0;
		}
	
	return 0;
}