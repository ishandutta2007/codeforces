#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=101000;
string s;
int main(){
	cin>>s;
	puts("3");
	puts("L 2");
	puts("R 2");
	printf("R %d",s.length()*2-1);
	return 0;
}