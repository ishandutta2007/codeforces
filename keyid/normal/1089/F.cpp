#include <bits/stdc++.h>
using namespace std;

int n;

void gcd(int a, int b, int &d, int &x, int &y){
    if(b){
        gcd(b, a % b, d, y, x);
        y -= a / b * x;
    }
    else{
        d = a; x = 1; y = 0;
    }
}

bool notp[100010];
int prime[100000], pcnt;

int main(){
	scanf("%d" , &n);

    for(int i = 2 ; i <= 100000 ; i++){
        if(!notp[i])prime[++pcnt] = i;
        for(int j = i + i ; j <= 100000 ; j += i)
			notp[j] = true;
    }

    vector<int> pf;

    int m = n;

    for(int i = 1 ; i <= pcnt ; i++){
		if(m % prime[i] == 0){
			pf.push_back(prime[i]);
			while(m % prime[i] == 0)
				m /= prime[i];
		}
	}

	if(m != 1)pf.push_back(m);

	if(pf.size() <= 1){
        puts("NO");
        return 0;
	}

    int p = pf[0], q = pf[1];

    int a, b, dd;
    gcd(p, q, dd, a, b);
    assert(dd == 1);
    assert((long long)p * a + (long long)q * b == 1);

    a = -a;b = -b;
	assert((a < 0 && b > 0) || (a > 0 && b < 0));
    if(a > 0){
        swap(p, q);
        swap(a, b);
    }

    int k = (-a) / q;
    a += k * q;
    b -= k * p;
    assert(a < 0 && b > 0);
    assert((long long)p * a + (long long)q * b == -1);

    a += n / p;
    assert(a > 0 && b > 0);
    assert((long long)p * a + (long long)q * b == n - 1);

    puts("YES");
    printf("2\n");
    printf("%d %d\n", a, n / p);
    printf("%d %d\n", b, n / q);

    return 0;
}