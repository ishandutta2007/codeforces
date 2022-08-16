#include <bits/stdc++.h>
using namespace std;
char a[200][200];
int b[200];
set<char> st;
char res[200];

bool match(char a[], char b[]){
	int i;
	for(i=0;a[i];i++)
		if(b[i]=='?')
			continue;
		else if (a[i]!=b[i])
			return false;
	return (b[i]==0);
}

int main(){
	int n,m,i,j;
	memset(a,0,sizeof a);
	cin >>n >> m;
	for(i=0;i<n;i++)
		scanf(" %s",a[i]);
	for(i=0;i<m;i++){
		scanf("%d",&j);
		b[j-1]=1;
	}

	for(i=0;i<100;i++){
		st.clear();
		for(j=0;j<n;j++)
			if(b[j] && a[j][i])
				st.insert(a[j][i]);
		if(st.empty()){
			res[i]=0;
			break;
		}
		else if(st.size()>1)
			res[i]='?';
		else
			res[i]=*st.begin();
	}
	for(i=0;i<n;i++)
		if(b[i] != match(a[i],res))
				break;
	if(i==n)
		printf("Yes\n%s\n",res);
	else
		printf("No\n");
}