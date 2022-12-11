#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;
typedef pair<int, int> pii;

void go(char c, int in, int n){

	if (c == 'h'){
		for (int i = 1; i <= 7 && n > 1; i++) if (i != in){
			printf(" %c%d", c, i);
			n--;
		}
		printf(" h8\n");
		return;
	}

	if (n - 2 >= 8){
		printf(" %c8", c);
		int cnt = 0;
		rep(i, 1, 7) if (i != in){
			printf(" %c%d", c, i);
			cnt++;
			if (cnt == 6){
				printf(" %c%d", c + 1, i);
				go(c + 1, i, n - 8);
				return;
			}
		}
	}
	else{// n - 2 < 8
		if (n == 2) printf(" %c8 h8\n", c);
		else{
			int now = in, cnt = 0, i = 1;

			while (cnt < n - 3 && i <= 7){
				if (i == in){
					i++;
					continue;
				}
				printf(" %c%d", c, i);
				now = i;
				i++;
				cnt++;
			}
			printf(" %c%d", c + 1, now);
			go(c + 1, now, 2);
		}
	}
}
int main(){
#ifdef local
	freopen("read.txt", "r", stdin);
#endif // local
	int n;
	scanf("%d", &n);
	printf("a1");
	go('a', 1, n);
    return 0;
}