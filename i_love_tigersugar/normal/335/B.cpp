#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAX   50505
using namespace std;
const int maxlen=26*99+1;
char s[MAX];
int f[maxlen+7][maxlen+7];
int c[30];
bool r[maxlen];
int n;
vector<char> res;
void init(void) {
	scanf("%s",&s[1]);
	n=strlen(&s[1]);
	memset(c,0,sizeof c);
	int i,j;
	for (i=1;i<=n;i=i+1) {
		c[s[i]-'a']++;
		if (c[s[i]-'a']>=100) {
			for (j=1;j<=100;j=j+1) printf("%c",s[i]);
			exit(0);
		}		
	}
	memset(r,false,sizeof r);
}
int max(const int &x,const int &y){
	if (x>y) return (x); else return (y);
}
void optimize(void) {
	int i,j;
	for (i=1;i<=n;i=i+1) {
		f[i][i]=1;
		f[i][i+1]=(s[i]==s[i+1])*2;
	}
	for (i=2;i<=n;i=i+1)
		for (j=1;j+i<=n;j=j+1) {
			if (s[j]==s[j+i]) f[j][j+i]=f[j+1][j+i-1]+2;
			else f[j][j+i]=max(f[j][j+i-1],f[j+1][j+i]);
		}			
}
void trace(void) {
	int i,j;
	i=1;
	j=n;
	while (true) {
		if (i==j) {
			r[j]=true;
			break;
		}
		if (i>j) break;
		if (s[i]==s[j]) {
			r[i]=true;
			r[j]=true;
			i++;j--;
		}
		else {
			if (f[i][j]==f[i][j-1]) j--;
			else i++;
		}
	}
	res.clear();
	for (i=1;i<=n;i=i+1)
		if (r[i]) res.push_back(s[i]);
	if (res.size()<100) {
		for (i=0;i<res.size();i=i+1) printf("%c",res[i]);		
	}
	else {
		for (i=0;i<=49;i=i+1) printf("%c",res[i]);
		for (i=49;i>=0;i=i-1) printf("%c",res[i]);
	}
}
int main(void) {
	init();
	optimize();
	trace();
	return 0;
}