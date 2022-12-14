#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<iomanip>
using namespace std;

int T , x , L; char str[2000003];

int main(){
	for(scanf("%d" , &T); T ; --T){
		scanf("%d %s" , &L , str + 1); int p = 1 , now = L;
		while(p <= L){
			int p1 = p; while(p1 < L && str[p1] == '<') ++p1;
			for(int i = L - p1 + 1 ; i <= L - p + 1 ; ++i) printf("%d " , i);
			now -= p1 - p + 1; p = p1 + 1;
		}
		putchar('\n'); p = 1;
		while(p <= L){
			int p1 = p; while(p1 < L && str[p1] == '>') ++p1;
			for(int i = p1 ; i >= p ; --i) printf("%d " , i);
			p = p1 + 1;
		}
		putchar('\n');
	}
	return 0;
}