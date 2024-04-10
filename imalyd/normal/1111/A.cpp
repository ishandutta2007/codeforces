#include<bits/stdc++.h>
using namespace std;
int rd(){
    int a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return rd();
}

const int N=1005;

int n;

char a[N],b[N];
int is(char a){return a=='a'||a=='e'||a=='i'||a=='o'||a=='u';}
int main(){
    scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	if(n!=strlen(b+1)){
		printf("No");return 0;
	}
	for(int i=1;i<=n;i++)if(is(a[i])!=is(b[i])){
		printf("No");return 0;
	}
	printf("Yes");
    return 0;
}