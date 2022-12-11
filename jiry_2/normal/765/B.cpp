#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ch[600];
int n,fir[50];
int main(){
	scanf("%s",ch+1);
	n=strlen(ch+1);
	memset(fir,0x3f,sizeof fir);
	for (int i=1;i<=n;i++)
		fir[ch[i]-'a']=min(fir[ch[i]-'a'],i);
	for (int i=0;i<26;i++)
		if (fir[i+1]<fir[i]){
			//cout<<"fa "<<fir[i+1]<<" "<<fir[i]<<endl;
			printf("NO\n"); return 0;
		}
	printf("YES\n");
	return 0;
}