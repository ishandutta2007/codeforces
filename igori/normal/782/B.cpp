#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int n;
typedef struct {
     int x, v;
} SSS;

SSS s[60000]={0};

bool can(int n, double time){
	double ma = s[0].x+time*s[0].v;
	double mi = s[0].x-time*s[0].v;
	for (int i = 1;i<n;i++){
		ma = min(ma,s[i].x+time*s[i].v);
		mi = max(mi,s[i].x-time*s[i].v);
		if (ma<mi) return false;
 	}
	return ma>=mi;
}

int main() {
     cin>>n;  
     for(int i=0; i<n; i++)  cin>>s[i].x;
     for(int i=0; i<n; i++)  cin>>s[i].v;

	double up=1000000000,down = 0,mid;
	while(up-down > 0.0000004){
		mid = (up+down)/2;
		if (can(n, mid)) up = mid;
		else	down = mid;
	}
	printf("%.6lf", mid);
}