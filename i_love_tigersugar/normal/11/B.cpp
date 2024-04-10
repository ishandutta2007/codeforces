#include<bits/stdc++.h>
int x;
void process(void) {
	int s=0;
	int i=0;
	scanf("%d",&x);
	if (x==0) {
		printf("0");
		exit(0);
	}
	if (x<0) x=-x;
	while (true) {
		i++;
		s+=i;
		if ((s>=x) && ((s-x)%2==0)) {
			printf("%d",i);
			return;
		}
	}
}
int main(void) {
	process();
	return 0;
}