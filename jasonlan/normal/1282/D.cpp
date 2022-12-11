#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=310;
int acnt,bcnt,ac,bc,cnt;
bool isb[maxn];
int querycnt(char a){
	int res=0;
	for(register int i=1;i<=300;++i)
		putchar(a);
	putchar('\n');
	cout.flush();
	scanf("%d",&res);
    if(!res)exit(0);
	return 300-res;
}
void queryisa(int p){
	int res=0;
	for(register int i=1;i<p;++i)
		putchar('a');
	putchar('b');
	for(register int i=p+1;i<=cnt;++i)
		putchar('a');
	putchar('\n');
	cout.flush();
	scanf("%d",&res);
    if(!res)exit(0);
	if(!(isb[p]=(res<bcnt)))--ac;
	else --bc;
}
int main(){
	ac=acnt=querycnt('a');
	bc=bcnt=querycnt('b');
	cnt=acnt+bcnt;
	for(register int i=1;i<=cnt&&ac&&bc;++i)
		queryisa(i);
	for(register int i=0;i<bc;++i)isb[cnt-i]=1;
	for(register int i=1;i<=cnt;++i)
		putchar('a'+isb[i]);
	cout.flush();
    exit(0);
	return 0;
}