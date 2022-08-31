/* Author - Ishan */
//DS includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>

//Other Includes
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>

//C Includes
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include <ctime>
#include <climits>


#define oo 0xBADC0DE
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define fill(a,v) memset(a, v, sizeof a)
#define all(x) x.begin(), x.end()
#define pb( z ) push_back( z )

using namespace std;
typedef pair<int,int> point;

#define INF 1000000000
#define Debug false
#define FASTIO 1
#define PRINT(x) cout << #x << " " << x << endl

typedef long long  Int64;
typedef short      Int16;
typedef char       Int8;
typedef unsigned long long  uInt64;
typedef unsigned short      uInt16;
typedef unsigned char       uInt8;

//typedef __builtin_popcount bitcount;
//typedef __gcd gcd

/* ***************************Fast IO******************************** */
/* *****IO optimizaton using fread_unlocked and fwrite_unlocked ***** */
#ifndef FASTIO
char *iIndex, *oIndex, InpFile[20000000], OutFile[20000000], DIP[20];
inline int input(int flag=0){
    while(*iIndex <= 32) ++iIndex;
    if(flag)return (*iIndex++ - '0'); /* For getting Boolean Characters */
    int x=0, neg = 0;char c;
    while(true){
       c=*iIndex++;
       if(c == '-') neg = 1;
       else {
           if (c<=32) return neg?-x:x;
           x=(x<<1)+(x<<3)+c-'0';
       }
    }
}
inline void output(int x,int flag){
    int y,dig=0;
    while (x||!dig) { y=x/10;DIP[dig++]=x-((y << 3) + (y << 1))+'0';x=y;}
    while (dig--) *oIndex++=DIP[dig];
    *oIndex++= flag ? '\n' : ' ';
}
inline void InitFASTIO(){
    iIndex = InpFile; oIndex = OutFile;
    fread_unlocked(InpFile,20000000,1,stdin);
}
inline void FlushFASTIO(){
    fwrite_unlocked(OutFile,oIndex-OutFile,1,stdout);
}
#endif

int main(){
    char w1[105],w2[105],w3[105];
    scanf("%s",w1);
    scanf("%s",w2);
    int l=strlen(w1);
    int l2=strlen(w2);
    
    if(l2!=l){printf("NO\n");return 0;}

    for(int i=0;i<l;i++)      w3[i]=w2[l-1-i];    w3[l]='\0';
    if(strcmp(w3,w1)==0)printf("YES\n");else printf("NO\n");
    return 0;
}