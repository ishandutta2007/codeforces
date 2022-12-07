#include <stdio.h>
#include <string.h>

int hh, mm;
int hhh, mmm;

int main() {
    scanf("%d%*c%d", &hh, &mm);
    scanf("%d%*c%d", &hhh, &mmm);
    int ansh, ansm;
    if (mm >= mmm) ansm = mm - mmm;
    else {ansm = mm + 60 - mmm; hh--;}
    if (hh >= hhh) ansh = hh - hhh;
    else ansh = hh + 24 - hhh;
    printf("%02d:%02d\n", ansh, ansm);
    return 0;
}