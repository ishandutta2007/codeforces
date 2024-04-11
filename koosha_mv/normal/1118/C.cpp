#include<iostream>
using namespace std;
int tedad[1009],a[100000],matrix[25][25];
int main(){
	int x,y,n,d1=0,d2=0,d0=0;cin>>n;
	for(int i=0;i<n*n;i++){
		cin>>a[i];
		tedad[a[i]]++;
		//cout<<a[i];
	}
	for(int i=1;i<=1000;i++){
	if(tedad[i]%2==1)
			d1++;
		if(tedad[i]%4>=2)
			d2++;
		if(tedad[i]%4==0)
			d0++;
	}
	x=0,y=0;
	if(n%2==1){
		if(!(d1==1 && d2<=n-1 && d2%2==0)){cout<<"NO";return 0;}
		cout<<"YES"<<endl;
		for(int i=1;i<=1000;i++){
			if(tedad[i]>=4){
				while(tedad[i]>=4 &&(y<n/2)){
					tedad[i]-=4;
					matrix[x][y]=i,matrix[x][n-y-1]=i,matrix[n-x-1][n-y-1]=i,matrix[n-x-1][y]=i;
					x++;
					if(x>=n/2){x=0,y++;}
					//cout<<y<<endl;
				}
			}
			if(tedad[i]%2==1){tedad[i]--;matrix[n/2][n/2]=i;}
		}
		//for(int i=1;i<4;i++)
		//cout<<i<<" : "<<tedad[i]<<"  ";cout<<endl;
		int t1=0,t2=0;
		for(int i=0;i<=1000;i++){
			while(tedad[i]){
				tedad[i]-=2;
				if(t1>t2){
					matrix[n/2][t2]=i,matrix[n/2][n-t2-1]=i,t2++;
				}
				else
					matrix[t1][n/2]=i,matrix[n-t1-1][n/2]=i,t1++;
			}
		}
	}
	else{
		if(d1 || d2){cout<<"NO";return 0;}
		x=0,y=0;
		cout<<"YES"<<endl;
		for(int i=1;i<=1000;i++){
			if(tedad[i]%4==0){
				while(tedad[i]>0){
					tedad[i]-=4;
					matrix[x][y]=i,matrix[x][n-y-1]=i,matrix[n-x-1][n-y-1]=i,matrix[n-x-1][y]=i;
					x++;
					if(x>n/2-1){x=0,y++;}
				}
			}
		}	
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}