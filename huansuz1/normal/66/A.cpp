#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

string s,c;
int n,i;

int main() {
	cin>>c;
	n=c.length(); 
	if (c[0]=='-')
	   		{         	
	   			for (i=1;i<n;i++)
	   				s=s+c[i];
	   			if (s<="128"&&n==4||n<4)
	   				printf("byte");
	   				else
	   			if (s<="32768"&&n==6||n<6)
	   				printf("short");
	   				else
	   			if (s<="2147483648"&&n==11||n<11)
	   				printf("int");
	   				else
	   			if (s<="9223372036854775808"&&n==20||n<20)
	   				printf("long");
	   				else
	   				printf("BigInteger");
	   		}
	   		else
	   		{
	   			s=c;
	   			if (s<"128"&&n==3||n<3)
	   				printf("byte");
	   				else
	   			if (s<"32768"&&n==5||n<5)
	   				printf("short");
	   				else
	   			if (s<"2147483648"&&n==10||n<10)
	   				printf("int");
	   				else
	   			if (s<"9223372036854775808"&&n==19||n<19)
	   				printf("long");
	   				else
	   				printf("BigInteger");

	   		}	

	return 0;
}