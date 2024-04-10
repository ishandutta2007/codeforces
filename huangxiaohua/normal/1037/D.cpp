#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,m,t,dep[200500],a[200500],x,y,it;
vector<int> v[200500];

int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dep[0]=-1;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		it++;
		if(dep[a[i]]<dep[a[i-1]]){puts("No");return 0;}
		for(auto j:v[a[i]]){
			if(dep[j]){continue;}
			dep[j]=it;
		}
	}
	if(a[1]!=1){puts("No");return 0;}
	puts("YES");
}