#include<bits/stdc++.h>
const char inva[]="illegal";
const char win1[]="the first player won";
const char win2[]="the second player won";
const char draw[]="draw";
const char mov1[]="first";
const char mov2[]="second";
char a[5][5];
int nx,no;
int xw,ow;
int win(const int &i,const char &c) {
    int j;
    int row=1;
    int col=1;
    for (j=1;j<=3;j=j+1) {
        if (a[i][j]!=c) row=0;
        if (a[j][i]!=c) col=0;
    }
    return (row+col);
}
void process(void) {
    int i,j;
    nx=0;
    no=0;
    for (i=2;i<=3;i=i+1) scanf("%s",&a[i][1]);
    for (i=1;i<=3;i=i+1)
        for (j=1;j<=3;j=j+1) {
            nx=nx+(a[i][j]=='X');
            no=no+(a[i][j]=='0');
        }
    if (nx<no) {
        printf("%s\n",inva);
        return;
    }
    if (nx>no+1) {
        printf("%s\n",inva);
        return;
    }
    xw=0;
    ow=0;
    for (i=1;i<=3;i=i+1) {
        xw=xw+win(i,'X');
        ow=ow+win(i,'0');
    }
    xw=xw+(a[1][1]=='X' && a[2][2]=='X' && a[3][3]=='X');
    xw=xw+(a[3][1]=='X' && a[2][2]=='X' && a[1][3]=='X');
    ow=ow+(a[1][1]=='0' && a[2][2]=='0' && a[3][3]=='0');
    ow=ow+(a[3][1]=='0' && a[2][2]=='0' && a[1][3]=='0');
    if (xw>0 && ow>0) {
        printf("%s\n",inva);
        return;
    }
    if (xw>0) {
        if (nx==no) printf("%s\n",inva);
        else printf("%s\n",win1);
        return;
    }
    if (ow>0) {
        if (nx>no) printf("%s\n",inva);
        else printf("%s\n",win2);
        return;
    }
    if (nx+no==9) {
        printf("%s\n",draw);
        return;
    }
    if (nx==no) {
        printf("%s\n",mov1);
        return;
    }
    printf("%s\n",mov2);
    return;
}
int main(void) {
    while (scanf("%s",&a[1][1])==1) process();
    return 0;
}