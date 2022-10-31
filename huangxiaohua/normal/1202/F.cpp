#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,k2,a,b,l,r,l1,r1,l2,r2,res;

vector<vector<int> >q;
int main(){
	scanf("%d%d",&a,&b);
	if(a>b){swap(a,b);}
	for(l=1;l<=a;l=r+1){
		k=a/l;r=a/k;
		l1=l;r1=r;
		if(l==r){
			if(l!=1&&(l-1)*(k+1)==a){l1=l-1;}
			l2=b/(k+1);
			if(b%(k+1)){l2++;}
			if(a%l){
				r2=b/k;
			}
			else{
				r2=(k==1)?b/k:b/(k-1);
			}
		}
		else{
			if(l!=1&&(l-1)*(k+1)==a){l1=l-1;}
			l2=b/(k+1);
			if(b%(k+1)){l2++;}
			r2=b/k;
		}
		if(l2<=r2){q.push_back({l1+l2,r1+r2});}
	}
	sort(q.begin(),q.end());
	for(i=0;i<q.size();i++){
		if(i==0||q[i][0]>q[i-1][1]){res+=q[i][1]-q[i][0]+1;}
		else{res+=q[i][1]-q[i-1][1];}
	}
	printf("%d",res);
}