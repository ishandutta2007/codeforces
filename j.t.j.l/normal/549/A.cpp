#include<iostream>
#include<cmath> 
#include<cstdio>
#include<algorithm>
#define N 200005
#define INF 0x4fffffff
#define PI 3.14159265358979323846
#define MM 1000000007
#include<string>
#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)

using namespace std;

int n,m,i,j,tot;
char a[100][100];
char w[10];

char IN(){
	char ch;
	scanf("%c",&ch);
	while ((ch<'a')||(ch>'z'))
		scanf("%c",&ch);
	return ch;
}

int check(int p, int q){
	w[1]=a[p][q];
	w[2]=a[p+1][q];
	w[3]=a[p][q+1];
	w[4]=a[p+1][q+1];
	sort(w+1,w+4+1);
	if ((w[1]=='a')&&(w[2]=='c')&&(w[3]=='e')&&(w[4]=='f'))
		return 1;
	else
		return 0;
}

int main(){
	string s;
	scanf("%d%d",&n,&m);
	getline(cin,s);
	rep(i,1,n){
		getline(cin,s);
		rep(j,1,m)
			a[i][j]=s[j-1];
	}
	tot=0;
	rep(i,1,n-1)
	rep(j,1,m-1)
		if (check(i,j))
			tot++;
	printf("%d\n",tot);
	return 0;
}