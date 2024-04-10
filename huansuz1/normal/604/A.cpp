#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<queue>
#include<cstdio>
#include<vector>
#define f first 
#define s second 
#define mp make_pair 
#define ll long long

using namespace std;


int p[20],m[20],w[20],hs,hu;


int main(){
	double x = 0;
	for(int i = 0;i < 5;++i) {
		scanf("%d",&m[i]);
		p[i] = (i + 1)*500;
	}
	for(int i = 0;i < 5;++i) {
		scanf("%d",&w[i]);
		x += max(0.3*p[i],(1 - 1.0*m[i]/250)*p[i] - 50*w[i]);
	}
	scanf("%d%d",&hs,&hu);
	x += 100*hs - 50*hu;
	int M = (int)(x + 0.5);
	cout<<M;

	return 0;
}