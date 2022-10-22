#include<bits/stdc++.h>
using namespace std;
int n,m,p;
int main(){
	scanf("%d%d%d",&n,&m,&p); int x;
	int pos1=-1;
	for (int i=0;i<n;i++){
		scanf("%d",&x);
		if (pos1==-1&&x%p) pos1=i;
	}
	int pos2=-1;
	for (int i=0;i<m;i++){
		scanf("%d",&x);
		if (pos2==-1&&x%p) pos2=i;
	}
	printf("%d\n",pos1+pos2);
	return 0;
}