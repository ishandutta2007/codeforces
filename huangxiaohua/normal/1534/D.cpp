#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 1000000007
int i,j,k,n,m,t,dep[5050],fa[5050],mx,sb1,sb2,a[5050];

vector<int> v1[5050],v[5050];

void ask(int x){
	printf("? %d\n",x);fflush(stdout);
}

void get1(){
	int i,j,k,l;
	for(i=1;i<=n;i++){
		if(dep[i]==2){
			v[1].push_back(i);
		}
	}
	for(i=3;i<=mx;i+=2){
		for(auto j:v1[i]){
			ask(j);
			for(k=1;k<=n;k++){
				scanf("%d",&l);
				if(l==1){
					if(dep[k]<dep[j]){v[k].push_back(j);}
					else{v[j].push_back(k);}
				}
			}
		}
	}
}

void get2(){
	int i,j,k,l;
	for(i=2;i<=mx;i+=2){
		for(auto j:v1[i]){
			ask(j);
			for(k=1;k<=n;k++){
				scanf("%d",&l);
				if(l==1){
					if(dep[k]<dep[j]){v[k].push_back(j);}
					else{v[j].push_back(k);}
				}
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	ask(1);
	for(i=1;i<=n;i++){
		scanf("%d",&k);k++;
		dep[i]=k;
		v1[k].push_back(i);
		mx=max(mx,k);
	}
	
	for(i=2;i<=mx;i++){
		if(i&1){sb1+=v1[i].size();}
		else{sb2+=v1[i].size();}
	}
	if(sb2>=sb1){
		get1();
	}
	else{
		get2();
	}
	puts("!");
	for(i=1;i<=n;i++){
		for(auto j:v[i]){
			printf("%d %d\n",i,j);
		}
	}
	fflush(stdout);
}