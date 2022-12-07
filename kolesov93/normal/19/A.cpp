#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <map>
#include <deque>
#include <string>
#include <string.h>
#define N 1111
struct cell {
	int score,num,goal,bal;
	
	bool operator <(const cell& A) const {
		if (score != A.score) return score > A.score;
		if (bal != A.bal) return bal > A.bal;
		if (goal != A.goal) return goal > A.goal;
		
		return 0;
	}
} e[N];
int n;
char w[N][111],a[111],b[111];
std::string res,res1;
std::map<std::string, int> q;

bool cmp(cell a, cell b) {
	res = w[a.num]; res1= w[b.num];
	return res < res1;
}

int main(void) {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%s",w[i]);
		res = w[i];
		q[res] = i;
		e[i].num = i;
	}
	
	for (int i=1;i<=n;i++) {
		for (int j=i+1;j<=n;j++) {
			scanf("%s",a);
			res = a;
			res1 = res.substr(res.find("-")+1);
			res = res.substr(0,res.find("-"));
			int a1,a2,num1=q[res],num2=q[res1];
			scanf("%d:%d",&a1,&a2);
			if (a1 > a2) { 
				e[num1].score += 3;
				e[num2].score += 0;
			}
			if (a1 < a2) { 
				e[num2].score += 3;
				e[num2].score += 0;
			} 
			if (a1 == a2) { 
				e[num1].score += 1;
				e[num2].score += 1;
			}  
			e[num1].goal += a1;
			e[num2].goal += a2;
			e[num1].bal += a1-a2;
			e[num2].bal += a2-a1;
		}
	}
	std::sort(e+1,e+n+1);
	std::sort(e+1,e+(n/2)+1,cmp);
	
	for (int i=1;i<=n/2;i++) puts(w[e[i].num]);
			
	return 0;
}