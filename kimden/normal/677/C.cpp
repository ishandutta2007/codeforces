#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000007

int f(char c){
	if(c>='0' && c<='9'){
		return (int)c-(int)'0';
	}
	if(c>='A' && c<='Z'){
		return 10+(int)c-(int)'A';
	}
	if(c>='a' && c<='z'){
		return 36+(int)c-(int)'a';
	}
	if(c=='-'){
		return 62;
	}
	if(c=='_'){
		return 63;
	}
	return -1;
}

int zeros(int a){
	int b = a;
	int c=0;
	for(int i=0;i<6;i++){
		if(b%2==0){
			c++;
		}
		b/=2;
	}
	return c;
}

int binpow(int q,int pw){
	if(pw==0)
		return 1;
	if(pw==1)
		return q;
	long long w = binpow(q,(int)(pw/2));
	long long e = w;
	w*=e;
	w%=MAXN;
	if(pw%2==1){
		w*=q;
		w%=MAXN;
	}
	return (int)w;
}

int main()
{
	char c='~';
	int d;
	long long n=1,m;
	long long p=0;
	c = getchar();
	while(c!=-1 && c!='\n' && c!='\0'){
		d = f(c);
		p += zeros(d);
		c = getchar();
	}
	n = binpow(3,p);
	cout << n;
	return 0;
}