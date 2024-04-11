#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef signed long long ll;
typedef unsigned long long u64;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

char ss[100][100]={
"111111101010101111100101001111111",
"100000100000000001010110001000001",
"101110100110110000011010001011101",
"101110101011001001111101001011101",
"101110101100011000111100101011101",
"100000101010101011010000101000001",
"111111101010101010101010101111111",
"000000001111101111100111100000000",
"100010111100100001011110111111001",
"110111001111111100100001000101100",
"011100111010000101000111010001010",
"011110000110001111110101100000011",
"111111111111111000111001001011000",
"111000010111010011010011010100100",
"101010100010110010110101010000010",
"101100000101010001111101000000000",
"000010100011001101000111101011010",
"101001001111101111000101010001110",
"101101111111000100100001110001000",
"000010011000100110000011010000010",
"001101101001101110010010011011000",
"011101011010001000111101010100110",
"111010100110011101001101000001110",
"110001010010101111000101111111000",
"001000111011100001010110111110000",
"000000001110010110100010100010110",
"111111101000101111000110101011010",
"100000100111010101111100100011011",
"101110101001010000101000111111000",
"101110100011010010010111111011010",
"101110100100011011110110101110000",
"100000100110011001111100111100000",
"111111101101000101001101110010001",
};
void solve() {
    int f,r,i,j,k,l,x,y;
    int ma=0;
    x = GETi();
    y = GETi();
    _P("%c\n",ss[x][y]);
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}