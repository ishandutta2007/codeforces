#include<iostream>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
//This code is written by Itst
using namespace std;

char s[500007] , t[500007];
int nxt[500007];

int main(){
    scanf("%s %s" , s + 1 , t + 1);
    int lS = strlen(s + 1) , lT = strlen(t + 1);
    nxt[0] = -1;
    for(int i = 1 ; i <= lT ; ++i){
	int cur = nxt[i - 1];
	while(cur != -1 && t[cur + 1] != t[i])
	    cur = nxt[cur];
	nxt[i] = cur + 1;
    }
    int cntS0 = 0 , cntS1 = 0 , cntT0 = 0 , cntT1 = 0 , cntCir0 = 0 , cntCir1 = 0;
    for(int i = 1 ; i <= lS ; ++i)
	if(s[i] == '0') ++cntS0;
	else ++cntS1;
    for(int i = 1 ; i <= nxt[lT] ; ++i)
	if(t[i] == '0') ++cntT0;
	else ++cntT1;
    for(int i = nxt[lT] + 1 ; i <= lT ; ++i)
	if(t[i] == '0') ++cntCir0;
	else ++cntCir1;
    if(cntS0 >= cntT0 && cntS1 >= cntT1){
	cntS0 -= cntT0; cntS1 -= cntT1;
	for(int i = 1 ; i <= nxt[lT] ; ++i)
	    putchar(t[i]);
    }
    while(cntS0 >= cntCir0 && cntS1 >= cntCir1){
	cntS0 -= cntCir0; cntS1 -= cntCir1;
	for(int i = nxt[lT] + 1 ; i <= lT ; ++i)
	    putchar(t[i]);
    }
    while(cntS0){putchar('0'); --cntS0;}
    while(cntS1){putchar('1'); --cntS1;}
    return 0;
}