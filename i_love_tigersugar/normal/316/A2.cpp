#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX   100100
struct bignum {
    int n; int d[MAX];
    bignum() {
        n = 0;
    }
    bignum(int x) {
        n = 0; memset(d, 0, sizeof d);
        while(x) d[n++] = x % 10, x /= 10;
    }
    bignum(const bignum &x) {
        n = x.n;
        memcpy(d, x.d, sizeof d);
    }
    bignum operator * (const int &x) {
        bignum res (*this);
        int rm = 0;
        for(int i = 0; i < n; ++i) {
            int p = d[i] * x + rm;
            res.d[i] = p % 10;
            rm = p / 10;
        }
        if(rm != 0) res.d[res.n++] = rm;
        return res;
    }
    bignum operator + (const bignum &x) {
        bignum res (*this);
        int N = max(n, x.n), rm = 0, p; res.n = N;
        for(int i = 0; i < N; ++i) {
            p = d[i] + x.d[i] + rm;
            res.d[i] = p % 10;
            rm = p / 10;
        }
        if(rm != 0) res.d[res.n++] = rm;
        return res;
    }
    /*void toString() {
        for(int i = 0; i < n; ++i) s[i] = d[i] + 0x30;
        s[n] = '\0'; reverse(s, s+n);
    }*/
	void print(void) {
		int i;
		for (i=n-1;i>=0;i=i-1) printf("%d",d[i]);
	}	
};
bool a[17];
bignum res;
int i,n,c,m;
char s[100100];
int main(void) {
	for (i='A';i<='J';i=i+1) a[i-'A']=true;
	res=bignum(1);
	scanf("%s",s);
	n=strlen(s);
	c=10;
	m=0;
	for (i=0;i<n;i=i+1) {
		if (s[i]=='?') {
			if (i==0) res=res*9;
			else m=m+1;
		}
		if (('A'<=s[i]) && (s[i]<='J')) {
			if (a[s[i]-'A']) {
				a[s[i]-'A']=false;
				res=res*(c-(i==0));
				c=c-1;				
			}				
		}	
	}	
	res.print();
	for (i=1;i<=m;i=i+1) printf("0");
	return 0;	
}