#include<bits/stdc++.h>
const int MAXN=1000000;
int N;
char a[MAXN+5];
int Next[MAXN+4];
template<class T>const T&min(const T&a,const T&b){
	return a<b?a:b;
}
template<class T>const T&max(const T&a,const T&b){
	return a>b?a:b;
}
int main(){
	scanf("%s",a+1);
	N=strlen(a+1);
	Next[1]=N;
	while(a[Next[2]+1]==a[Next[2]+2])
		++Next[2];
	for(int i=3,j=2;i<=N;++i){
		int p=j+Next[j]-1,L=Next[i-j+1];
		if(i+L<=p)
			Next[i]=L;
		else{
			Next[i]=max(0,p-i+1);
			while(a[Next[i]+i]==a[Next[i]+1])
				++Next[i];
			j=i;
		}
	}
	int Max=0;
	for(int i=2;i<=N;++i)
		Max=max(Max,min(Next[i],N-i));
	int Ans=0;
	for(int i=2;i<=N;++i)
		if(Next[i]==N-i+1&&Max>=N-i+1)
			Ans=max(Ans,N-i+1);
	if(Ans)
		for(int i=1;i<=Ans;++i)
			putchar(a[i]);
	else
		puts("Just a legend");
	return 0;
}