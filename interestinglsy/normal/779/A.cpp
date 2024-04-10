#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define pb push_back
#define mp make_pair
#define INF 9999999
#define LINF 9999999999999999
#define SINF "%"
#define uint unsigned int
#define msn(a,v) memset(a,v,sizeof(a))
#define ms(a) msn(a,0)
#define NONE -1
#define allowxout 1
#define ll long long
#define ull unsigned ll
#define uchar unsigned char
#define xout(a) if(allowxout) cout << "[X] " << a << " "
#define xout2(a,b) if(allowxout) cout << "[X2] " << a << " " << b << " "
#define xoutln(a) if(allowxout) cout << "[X] " << a << endl
#define xout2ln(a,b) if(allowxout) cout << "[X2] " << a << " " << b << endl
using namespace std;

int n;
int a[105];
int b[105];

int numa[6];
int numb[6];
int num[6];

int main(){
	//freopen("A.txt","r",stdin);
	
	while(scanf("%d",&n) != EOF){
		ms(numa); ms(numb); ms(num);
		
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
			numa[a[i]]++;
			num[a[i]]++;
		}
		for(int i = 1;i <= n;i++){
			scanf("%d",&b[i]);
			numb[b[i]]++;
			num[b[i]]++;
		}
		
		bool con = 0;
		for(int i = 1;i <= 5;i++)
			if(num[i] & 1){
				printf("-1\n");
				con = 1;
				break;
			}
		if(con) continue;
		
		int ans = 0;
		for(int i = 1;i <= 5;i++)
			ans += abs((numa[i] - numb[i])/2);
		
		printf("%d\n",ans/2);
	}
	return 0;
}