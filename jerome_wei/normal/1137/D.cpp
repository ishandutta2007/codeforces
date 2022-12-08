#include<bits/stdc++.h>
using namespace std;

int group[20];

inline void Move(vector<int> S){
	printf("next ");
	for(size_t i=0;i<S.size();i++){
		printf("%d ",S[i]);
	}puts("");
	fflush(stdout);
	int t;scanf("%d",&t);
	for(int T=1;T<=t;T++){
		char x=0;
		while(x<'0'||x>'9')x=getchar();
		while(x>='0'&&x<='9')group[x-'0']=T,x=getchar();
	}
}
int a[]= {0,1,2,3,4,5,6,7,8,9};
vector<int> fast(1,0),slow(1,1),others(a+2,a+10);
vector<int> total(a,a+2),all(a,a+10);
int main()
{
//	cout<<fast[0]<<" "<<slow[0]<<" "<<total[0]<<endl;
	while(true){
		Move(total);
		Move(fast);
		if(group[1]==group[0])break;
	}
	while(true){
		Move(all);
		if(group[1]==group[2])break;
	}
	puts("done");
}