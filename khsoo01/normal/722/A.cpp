#include<bits/stdc++.h>
using namespace std;
int f, ans = 1e9, idx;
char ipt[55];

bool valid(int X) {
    int A = X/100, B = X%100;
    if(f == 12) {
        if(1<=A && A<=12 && 0<=B && B<60) return true;
        else return false;
    }
    else {
        if(0<=A && A<=23 && 0<=B && B<60) return true;
        else return false;
    }
}

int diff (int X) {
    int A = X/1000+'0';
    int B = (X%1000)/100+'0';
    int C = (X%100)/10+'0';
    int D = X%10+'0';
    return (A!=ipt[0]) + (B!=ipt[1]) + (C!=ipt[3]) + (D!=ipt[4]);
}

int main()
{
    scanf("%d%s",&f,&ipt);
    for(int i=0;i<10000;i++) {
        if(valid(i)) {if(ans > diff(i)) {ans = diff(i); idx = i;}}
    }
    printf("%02d:%02d\n",idx/100,idx%100);
}