#include<cstdio>
#include<cstring>
char s[1005];
int n;
int pos0[4][2]={{0,0},{2,0},{0,1},{2,1}};
int pos1[4][2]={{0,2},{1,2},{2,2},{3,2}};
int main(){
	scanf("%s",s);n=strlen(s);
	int p0=0,p1=0;
	for(int i=0;i<n;++i){
		if(s[i]=='0'){printf("%d %d\n",pos0[p0][0]+1,pos0[p0][1]+1);p0=(p0+1)%4;}
		else{printf("%d %d\n",pos1[p1][0]+1,pos1[p1][1]+1);p1=(p1+1)%4;}
	}
	return 0;
}