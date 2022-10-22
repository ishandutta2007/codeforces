#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define LL long long
#define N 200050
using namespace std;
int n,top=0;
int fa[50];
int a[N],b[N];
char s[N],A[N],B[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	int p,q;
	for(int i=1;i<=26;i++) fa[i]=i;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) a[i]=s[i]-'a'+1;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) b[i]=s[i]-'a'+1;
    for(int i=1;i<=n;i++){
    	p=find(a[i]);q=find(b[i]);
    	if(p==q) continue;
    	else{
    		top++;
    		A[top]=p+'a'-1;
    		B[top]=q+'a'-1;
    		fa[p]=q;
		}
	}
	printf("%d\n",top);
	for(int i=1;i<=top;i++)
		printf("%c %c\n",A[i],B[i]);
	return 0;
}