#include <stdio.h>
#include <string.h>

int n, m, Min, Max, num[105];

bool judge() {
    int f1 = 0, f2 = 0;
    for (int i = 0; i < m; i++) {
	if (num[i] < Min || num[i] > Max)
	    return false;
	if (num[i] == Min) f1--;
	if (num[i] == Max) f2--;
    }
    int yu = n - m;
    if (!f1) yu--;
    if (!f2) yu--;
    if (yu < 0) return false;
    return true;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &Min, &Max);
    for (int i = 0; i < m; i++)
	scanf("%d", &num[i]);
    if (judge()) printf("Correct\n");
    else printf("Incorrect\n");
    return 0;
}