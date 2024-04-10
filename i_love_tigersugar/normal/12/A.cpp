#include<bits/stdc++.h>
const char yes[]="YES";
const char no[]="NO";
char a[5][5];
void answer_no(void) {
	printf("%s",no);
	exit(0);
}
int main(void) {
	scanf("%s",a[0]);
	scanf("%s",a[1]);
	scanf("%s",a[2]);
	if (a[0][0]!=a[2][2]) answer_no();
	if (a[0][1]!=a[2][1]) answer_no();
	if (a[0][2]!=a[2][0]) answer_no();
	if (a[1][0]!=a[1][2]) answer_no();
	printf("%s",yes);
	return 0;
}