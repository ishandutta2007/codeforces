#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int v[21];
int v2[21];
bool b[21];
int val[21];
int somadif=0;
int dif;
int resposta=0;

void resp(int p,int n, int l, int r, int x){
	if (p!=n){
			val[p]=v[p];
			somadif+=v[p];
			resp(p+1,n,l,r,x);
			val[p]=0;
			somadif-=v[p];
			resp(p+1,n,l,r,x);

	}
	if (p==n){
		for (int i=0;i<21;i++){
			v2[i]=val[i];
		}
		sort(v2,v2+20);
		int min=1123456,max=0;
		for (int i=0;i<21;i++){
			if (v2[i]<min && v2[i]!=0){
				min=v2[i];
			}
			if (v2[i]>max){
				max=v2[i];
			}
		}
		if(somadif>=l && somadif<=r && (max-min)>=x){
			resposta++;
		}
		
		
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,l,r,x;
	cin>>n>>l>>r>>x;
	for (int i=0; i<n; i++){
		cin>>v[i];
	}
	resp(0,n,l,r,x);
	cout<<resposta<<"\n";
	return 0;
}