#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,a[3050],mx,mn,n1,it=1;
char s[20050];
vector<int> v;
int get(){
	int i,j,k=0,b[5050]={0},n;
	n=n1;
	for(i=1;i<=n;i++){b[i]=a[i];}
	while(1){
		for(i=1;i<=n;i++){
			if(b[i]!=i){goto aaa;}
		}
		return k;
		aaa:k++;
		for(i=n;i>=1;i--){
			if(b[i]>i&&b[i]!=b[i-1]+1){b[i]--;}
		}
	}
}

void print(int x){
	if (x>9)print(x/10);
	putchar(x%10+'0');
}

int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(i=1;i<=n;i++){
		if(s[i]=='L'){a[++n1]=i;}
	}
	n=n1;
	if(!n){puts("-1");return 0;}
	for(i=1;i<=n;i++){mx+=a[i]-i;}
	mn=get();
	if(m<mn||m>mx){puts("-1");return 0;}
	for(i=1;i<=m;i++){
		v.clear();
		if(mx==m){
			while(a[it]==it){it++;}
			print(1);putchar(' ');
			print(a[it]-1);putchar(' ');
			a[it]--;
		}
		else{
			mx++;
			for(j=n;j>=1;j--){
				if(a[j]>j&&a[j-1]!=a[j]-1&&mx>m){
					mx--;v.push_back(a[j]-1);a[j]--;
				}
			}
			print(v.size());putchar(' ');
			for(auto i:v){
				print(i);putchar(' ');
			}
		}
		putchar('\n');
	}
}