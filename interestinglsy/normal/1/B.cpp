//CF 1B
#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#define ll long long
using namespace std;

unsigned int t,ti;

string turn[1000001];	//turn[i] i   (such as   turn[25]="Y"

/*-----------------B a s i c--------------------*/
ll pow10(int x){
	if(x==0)return  1;
	if(x==1)return  10;
	if(x==2)return  100;
	if(x==3)return  1000;
	if(x==4)return  10000;
	if(x==5)return  100000;
	if(x==6)return  1000000;
	if(x==7)return  10000000;
	if(x==8)return  100000000;
	if(x==9)return  1000000000;
	if(x==10)return 10000000000;
	return          100000000000;
}
bool j_letter(char c){
	if(c >= 'A' && c <= 'Z')return true;
	return false;
}
bool j_num(char c){
	if(c >= '0' && c <= '9')return true;
	return false;
}
int g_id(char c){
	return c-'A'+1;
}
char g_letter(int c){
	return c+'A'-1;
}
int g_num(char c){
	return c-'0';
}
string substring(string s,int begin,int end){
	int k;
	string str = "";
	for(k = begin;k <= end;k++)
		str += s[k];
	return str;
}

/*---------------F u n c t i o n----------------*/	
void __init__(void){
	
	int k,j,len,l;
	ll value;
	int digit[10086];
	string now="A";
	
	for(k = 1;k <= 1000000;k++){
		turn[k] = now;
		len = now.length();
		memset(digit,0,sizeof(digit));
		for(j = 1,l = len;j <= len;j++,l--)digit[l] = g_id(now[j-1]);
		digit[1]++; now = "";
		for(j = 1;j <= len;j++)
			if(digit[j] >= 27){
				digit[j+1]++;
				digit[j] = 1;	// 1 ,1A :] 
			}
		if(digit[len+1] != 0) len++;
		for(j = 1;j <= len;j++) now = g_letter(digit[j]) + now;
	}
}

void turn1(string s){	//turn1:	BC23 -> R23C55
	int pos = 0,k,len = s.length();
	string r;
	ll c = 0;
	for(;j_letter(s[pos]);pos++);
	for(k = 0;k < pos;k++){
		c *= 26;
		c += g_id(s[k]);
	}
	r = substring(s,pos,len-1);
	cout << 'R' << r << 'C' << c <<endl;
}
void turn2(string s){
	int pos = 1,k,l,len = s.length();	// 1 ,1 :D 
	string r="";
	ll c=0;
	
	for(;j_num(s[pos]);pos++);
	r = substring(s,1,pos-1);
	for(k = pos+1,l = len-pos-2;k < len;k++,l--){
		c += (g_num(s[k]) * pow10(l));
	}
	cout << turn[c] << r << endl;
}
void solve(string s){
	int pos = 0, len = s.length();
	string s_ = s;
	s_ += "@";
	for(;j_letter(s[pos]);pos++);
	for(;j_num(s[pos]);pos++);
	if(s_[pos] == '@')turn1(s);
	else turn2(s);
}

/*-------------------M A I N--------------------*/	

//	R 2 3 C 5 5
//	B C 2 3
//	0 1 2 3 4 5 6

int main(){
	__init__();
	//freopen("1B.txt","r",stdin);
	cin >> t;
	for(ti = 1;ti <= t;ti++){
		string inp;
		cin >> inp;
		solve(inp);
	}
	return 0;
	cout << "LSY IS HANDSOME\n";
}