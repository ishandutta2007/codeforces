#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main(){
	const double pi = acos(-1);
	int n,rr,r;
	cin >> n >> rr >> r;
	if(r>rr){
		cout << "NO";
		return 0;
	}
	if(2*r>rr){
		if(n==1){
			cout << "YES";
		}else{
			cout << "NO";
		}
		return 0;
	}
	if(2*r==rr){
		if(n<=2){
			cout << "YES";
		}else{
			cout << "NO";
		}
		return 0;
	}
	long double sn,cn,q,w,q1,w1;
	sn = 0;
	cn = 1;
	q = ((long double)r)/((long double)(rr-r));
	w = sqrt(1-q*q);
	for(int i=0;i<n;i++){
		q1 = sn;
		w1 = cn;
		sn = q1*w+w1*q;
		cn = w1*w-q1*q;
	}
	if(sn>-1e-8){
		cout << "YES";
	}else{
		cout << "NO";
	}
    return 0;
}